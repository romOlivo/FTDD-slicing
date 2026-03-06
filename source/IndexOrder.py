"""
index_ordering.py  (v3)

Exports:
    compute_index_order              — greedy (mult=1 por defecto)
    compute_rcm_order                — Reverse Cuthill-McKee puro
    compute_index_order_rcm_sifting  — RCM inicialización + sifting local
    compute_index_order_rcm_tiebreak — greedy con RCM como desempate
    select_and_compute_order         — selector automático por propiedades del grafo
    cut_width_profile                — métrica corregida
    explain_order                    — pretty-printer
"""

import statistics
from collections import defaultdict


# ══════════════════════════════════════════════════════════════════════════════
# Shared simulation helper
# ══════════════════════════════════════════════════════════════════════════════

def _simulate_path(tensors, path):
    working = [set(t) for t in tensors]
    scheduled_step = {}
    last_seen = defaultdict(int)

    for step, (i, j) in enumerate(path):
        contracted = working[i] & working[j]
        surviving  = working[i] ^ working[j]
        for idx in contracted:
            if idx not in scheduled_step:
                scheduled_step[idx] = step
            last_seen[idx] = step
        for idx in surviving:
            last_seen[idx] = step
        for pos in sorted([i, j], reverse=True):
            working.pop(pos)
        working.append(surviving)

    return scheduled_step, last_seen


# ══════════════════════════════════════════════════════════════════════════════
# Graph structure metrics
# ══════════════════════════════════════════════════════════════════════════════

def _build_interaction_graph(tensors):
    """Devuelve el grafo de interacción como dict idx -> set of neighbors."""
    adj = defaultdict(set)
    for t in tensors:
        for i in range(len(t)):
            for j in range(i + 1, len(t)):
                adj[t[i]].add(t[j])
                adj[t[j]].add(t[i])
    return adj


def graph_metrics(tensors):
    """
    Calcula métricas estructurales del grafo de interacción de índices.

    Returns
    -------
    dict con:
        irregularity   : coeficiente de variación de grados (std/mean)
                         alto => RQC/QNN, bajo => QFT/QWalk
        avg_degree     : grado medio
        density        : densidad del grafo (aristas / aristas posibles)
        max_clique_ratio: tamaño de la mayor puerta (tensor) / n_indices
                         alto => muchas interacciones locales densas (QFT)
    """
    adj = _build_interaction_graph(tensors)
    if not adj:
        return {"irregularity": 0.0, "avg_degree": 0.0,
                "density": 0.0, "max_clique_ratio": 0.0}

    degrees = [len(neighbors) for neighbors in adj.values()]
    n = len(degrees)
    mean_deg = statistics.mean(degrees)
    std_deg  = statistics.stdev(degrees) if n > 1 else 0.0
    irregularity = std_deg / mean_deg if mean_deg > 0 else 0.0

    max_tensor_size = max(len(t) for t in tensors)
    max_clique_ratio = max_tensor_size / n if n > 0 else 0.0

    density = mean_deg / (n - 1) if n > 1 else 0.0

    return {
        "irregularity"   : irregularity,
        "avg_degree"     : mean_deg,
        "density"        : density,
        "max_clique_ratio": max_clique_ratio,
    }


# ══════════════════════════════════════════════════════════════════════════════
# Free index ordering helper
# ══════════════════════════════════════════════════════════════════════════════

def _ordenar_libres_por_paso_contraccion(tensors, path, indices_libres):
    libre_a_tensor_original = {}
    for idx_libre in indices_libres:
        for i, t in enumerate(tensors):
            if idx_libre in t:
                libre_a_tensor_original[idx_libre] = i
                break

    paso_aparicion_tensor = {}
    working_indices = list(range(len(tensors)))

    for step, (i, j) in enumerate(path):
        for pos in [i, j]:
            t = working_indices[pos]
            if isinstance(t, int) and t not in paso_aparicion_tensor:
                paso_aparicion_tensor[t] = step

        t_a = working_indices[i]
        t_b = working_indices[j]
        herencia = set()
        for t in [t_a, t_b]:
            if isinstance(t, int):
                herencia.add(t)
            else:
                herencia.update(t)
        for pos in sorted([i, j], reverse=True):
            working_indices.pop(pos)
        working_indices.append(herencia)

    def _prioridad(idx_libre):
        tensor_orig = libre_a_tensor_original.get(idx_libre)
        return -paso_aparicion_tensor.get(tensor_orig, float('inf'))

    return sorted(indices_libres, key=_prioridad)


# ══════════════════════════════════════════════════════════════════════════════
# Method 1: Greedy
# ══════════════════════════════════════════════════════════════════════════════

def compute_index_order(tensors, path, mult=1):
    """Orden greedy derivado del path de contracción."""
    working = [set(t) for t in tensors]
    scheduled_step = {}
    last_seen = defaultdict(int)

    for step, (i, j) in enumerate(path):
        contracted = working[i] & working[j]
        surviving  = working[i] ^ working[j]
        for idx in contracted:
            if idx not in scheduled_step:
                scheduled_step[idx] = step
            last_seen[idx] = step
        for idx in surviving:
            last_seen[idx] = step
        for pos in sorted([i, j], reverse=True):
            working.pop(pos)
        working.append(surviving)

    all_indices  = {idx for tensor in tensors for idx in tensor}
    free_indices = all_indices - set(scheduled_step.keys())

    contracted_sorted = sorted(
        scheduled_step.keys(),
        key=lambda idx: (scheduled_step[idx], mult * last_seen[idx], idx)
    )
    return contracted_sorted + _ordenar_libres_por_paso_contraccion(
        tensors, path, free_indices)


# ══════════════════════════════════════════════════════════════════════════════
# Method 2: RCM
# ══════════════════════════════════════════════════════════════════════════════

def compute_rcm_order(tensors):
    """Reverse Cuthill-McKee sobre el grafo de interacción de índices."""
    adj = _build_interaction_graph(tensors)
    all_indices = sorted(list(adj.keys()))
    if not all_indices:
        return []

    ordered   = []
    remaining = set(all_indices)

    while remaining:
        start_node = min(remaining, key=lambda x: len(adj[x]))
        queue = [start_node]
        remaining.remove(start_node)
        level_order = [start_node]

        while queue:
            current = queue.pop(0)
            neighbors = sorted(
                [n for n in adj[current] if n in remaining],
                key=lambda x: len(adj[x])
            )
            for n in neighbors:
                if n in remaining:
                    remaining.remove(n)
                    queue.append(n)
                    level_order.append(n)

        ordered.extend(level_order)

    return ordered[::-1]


# ══════════════════════════════════════════════════════════════════════════════
# Method 3: RCM + sifting local  (Opción A)
# ══════════════════════════════════════════════════════════════════════════════

def compute_index_order_rcm_sifting(tensors, path, window=3, max_passes=3):
    """
    Inicializa con RCM y refina con sifting local restringido a una ventana.

    Parameters
    ----------
    window     : número de posiciones a cada lado que se prueban por índice
    max_passes : número de pasadas completas sobre el orden
    """
    order = compute_rcm_order(tensors)
    if not order:
        return order

    def _total_cutwidth(o):
        return sum(cut_width_profile(tensors, path, o))

    improved = True
    passes   = 0

    while improved and passes < max_passes:
        improved = False
        passes  += 1

        for k in range(len(order)):
            best_order = order[:]
            best_cost  = _total_cutwidth(best_order)

            lo = max(0, k - window)
            hi = min(len(order) - 1, k + window)

            for target in range(lo, hi + 1):
                if target == k:
                    continue
                candidate      = order[:]
                idx            = candidate.pop(k)
                candidate.insert(target, idx)
                cost           = _total_cutwidth(candidate)
                if cost < best_cost:
                    best_cost  = cost
                    best_order = candidate

            if best_order != order:
                order    = best_order
                improved = True

    return order


# ══════════════════════════════════════════════════════════════════════════════
# Method 4: Greedy con RCM como desempate  (Opción B)
# ══════════════════════════════════════════════════════════════════════════════

def compute_index_order_rcm_tiebreak(tensors, path, mult=1):
    """
    Greedy puro, pero cuando dos índices tienen el mismo scheduled_step
    y el mismo last_seen, se desempata con la posición en el orden RCM.
    """
    scheduled_step, last_seen = _simulate_path(tensors, path)

    all_indices  = {idx for tensor in tensors for idx in tensor}
    free_indices = all_indices - set(scheduled_step.keys())

    rcm_order    = compute_rcm_order(tensors)
    rcm_position = {idx: k for k, idx in enumerate(rcm_order)}
    n            = len(rcm_order)

    contracted_sorted = sorted(
        scheduled_step.keys(),
        key=lambda idx: (
            scheduled_step[idx],
            mult * last_seen[idx],
            rcm_position.get(idx, n),   # RCM como tercer desempate
            idx                          # nombre como cuarto desempate
        )
    )
    return contracted_sorted + _ordenar_libres_por_paso_contraccion(
        tensors, path, free_indices)


# ══════════════════════════════════════════════════════════════════════════════
# Selector automático
# ══════════════════════════════════════════════════════════════════════════════

def select_and_compute_order(tensors, path,
                             irregularity_threshold=0.5,
                             density_threshold=0.3,
                             method_high_irregularity="rcm",
                             method_low_irregularity="greedy",
                             verbose=False,
                             **kwargs):
    """
    Selecciona el método de ordenación basándose en propiedades estructurales
    del grafo de interacción de índices.

    Lógica por defecto
    ------------------
    La irregularidad alta (RQC, QNN) favorece RCM porque el grafo es
    irregular y el RCM minimiza el ancho de banda local de forma eficaz.

    La irregularidad baja (QFT, QWalk) favorece greedy porque la estructura
    regular tiene un orden "natural" que el path de contracción ya captura.

    La densidad alta con irregularidad baja es característica de QFT
    (grafo de intervalo casi completo) y refuerza la elección de greedy.

    Parameters
    ----------
    irregularity_threshold    : umbral sobre el coeficiente de variación
                                de grados. Ajustar según benchmarks.
    density_threshold         : umbral secundario sobre densidad del grafo.
    method_high_irregularity  : método cuando irregularity > threshold.
                                Opciones: "rcm", "greedy", "rcm_sifting",
                                          "rcm_tiebreak"
    method_low_irregularity   : método cuando irregularity <= threshold.
                                Mismas opciones.
    verbose                   : imprime las métricas y el método elegido.
    **kwargs                  : argumentos adicionales pasados al método
                                elegido (e.g. window=5, mult=1).

    Returns
    -------
    list of str  --  orden de índices
    """
    methods = {
        "greedy"       : compute_index_order,
        "rcm"          : lambda t, p, **kw: compute_rcm_order(t),
        "rcm_sifting"  : compute_index_order_rcm_sifting,
        "rcm_tiebreak" : compute_index_order_rcm_tiebreak,
    }

    metrics = graph_metrics(tensors)
    irr     = metrics["irregularity"]
    den     = metrics["density"]

    # Lógica de selección: irregularidad es la señal principal,
    # densidad actúa como señal secundaria para refinar el caso límite
    if irr > irregularity_threshold:
        chosen = method_high_irregularity
    elif den > density_threshold:
        # Baja irregularidad + alta densidad = estructura tipo QFT
        chosen = method_low_irregularity
    else:
        chosen = method_low_irregularity

    if verbose:
        print(f"  [selector] irregularity={irr:.3f}  density={den:.3f}")
        print(f"  [selector] método elegido: {chosen}")

    fn = methods.get(chosen)
    if fn is None:
        raise ValueError(f"Método desconocido: '{chosen}'. "
                         f"Opciones: {list(methods.keys())}")

    return fn(tensors, path, **kwargs)


# ══════════════════════════════════════════════════════════════════════════════
# Diagnostics  (cut-width corregido)
# ══════════════════════════════════════════════════════════════════════════════

def cut_width_profile(tensors, path, order):
    """
    Cut-width en la posición k = número de índices internos que aparecen
    después de la posición k en el orden (= siguen 'abiertos' en ese nivel).
    """
    scheduled_step, _ = _simulate_path(tensors, path)
    internal    = set(scheduled_step.keys())
    position_of = {idx: k for k, idx in enumerate(order)}

    profile = []
    for k in range(len(order)):
        open_count = sum(
            1 for idx in internal
            if position_of.get(idx, len(order)) > k
        )
        profile.append(open_count)

    return profile


def explain_order(tensors, path, order, label=""):
    profile = cut_width_profile(tensors, path, order)
    if label:
        print(f"[{label}]")
    print("  Order : " + " < ".join(order))
    print(f"  {'Pos':<5} {'Index':<16} Cut-width")
    print("  " + "-" * 38)
    for k, (idx, cw) in enumerate(zip(order, profile)):
        print(f"  {k:<5} {idx:<16} {cw}  {'█' * cw}")
    print(f"  Max cut-width        : {max(profile)}")
    print(f"  Sum (TDD cost proxy) : {sum(profile)}")
    print()