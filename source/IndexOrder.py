from collections import defaultdict


# ══════════════════════════════════════════════════════════════════════════════
#                                   Constants
# ══════════════════════════════════════════════════════════════════════════════


INDEX_ORDER_DEFAULT = "default"
INDEX_ORDER_PATH = "path"
INDEX_ORDER_RCM = "rcm"


# ══════════════════════════════════════════════════════════════════════════════
#                 Support methods for calculating the ordering
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


def _rearrange_free_indices(tensors, path, free_indices):
    free_2_original_tensor = {}
    for idx_free in free_indices:
        for i, t in enumerate(tensors):
            if idx_free in t:
                free_2_original_tensor[idx_free] = i
                break

    tensor_appear = {}
    working_indices = list(range(len(tensors)))

    for step, (i, j) in enumerate(path):
        for pos in [i, j]:
            t = working_indices[pos]
            if isinstance(t, int) and t not in tensor_appear:
                tensor_appear[t] = step

        t_a = working_indices[i]
        t_b = working_indices[j]
        heredity = set()
        for t in [t_a, t_b]:
            if isinstance(t, int):
                heredity.add(t)
            else:
                heredity.update(t)
        for pos in sorted([i, j], reverse=True):
            working_indices.pop(pos)
        working_indices.append(heredity)

    def _priority(idx_free):
        tensor_orig = free_2_original_tensor.get(idx_free)
        return -tensor_appear.get(tensor_orig, float('inf'))

    return sorted(free_indices, key=_priority)


# ══════════════════════════════════════════════════════════════════════════════
#                              Ordering methods
# ══════════════════════════════════════════════════════════════════════════════

def _compute_rcm_order(tensors):
    """ Reverse Cuthill-McKee """
    adj = _build_interaction_graph(tensors)
    all_indices = sorted(list(adj.keys()))
    if not all_indices:
        return []

    ordered = []
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


def _compute_path_order(tensors, path, mult=1):
    """ Order based in the contraction path"""
    working = [set(t) for t in tensors]
    scheduled_step = {}
    last_seen = defaultdict(int)

    for step, (i, j) in enumerate(path):
        contracted = working[i] & working[j]
        surviving = working[i] ^ working[j]
        for idx in contracted:
            if idx not in scheduled_step:
                scheduled_step[idx] = step
            last_seen[idx] = step
        for idx in surviving:
            last_seen[idx] = step
        for pos in sorted([i, j], reverse=True):
            working.pop(pos)
        working.append(surviving)

    all_indices = {idx for tensor in tensors for idx in tensor}
    free_indices = all_indices - set(scheduled_step.keys())

    contracted_sorted = sorted(
        scheduled_step.keys(),
        key=lambda idx: (scheduled_step[idx], mult * last_seen[idx], idx)
    )
    return contracted_sorted + _rearrange_free_indices(
        tensors, path, free_indices)


# ══════════════════════════════════════════════════════════════════════════════
#                             Exporting methods
# ══════════════════════════════════════════════════════════════════════════════


def calculate_order(order_method, tensors, path, default):
    if order_method == INDEX_ORDER_DEFAULT:
        return default
    tensors_index = [[i.key for i in elem.index_set] for elem in tensors]
    if order_method == INDEX_ORDER_RCM:
        return _compute_rcm_order(tensors_index)
    if order_method == INDEX_ORDER_PATH:
        return _compute_path_order(tensors_index, path)
    return default
