from qiskit.circuit.library import RXGate, RZGate, RYGate
from source.TDD_Q import get_real_qubit_num
from qiskit import QuantumCircuit
import math


def generar_malla_n_qubits(n):
    """
    Genera un diccionario de adyacencia para una malla cuadrada (grid)
    de N cúbits.
    """
    grid_size = math.ceil(math.sqrt(n))
    topologia = {}

    for i in range(n):
        fila, col = divmod(i, grid_size)
        vecinos = []

        # Posibles vecinos: Arriba, Abajo, Izquierda, Derecha
        posibles = [(fila - 1, col), (fila + 1, col), (fila, col - 1), (fila, col + 1)]

        for f, c in posibles:
            if 0 <= f < grid_size and 0 <= c < grid_size:
                vecino_idx = f * grid_size + c
                if vecino_idx < n:
                    vecinos.append(vecino_idx)

        topologia[i] = vecinos
    return topologia


def get_crosstalk_noise(qubits_afectados, epsilon_xtalk=0.002, topologia=None):
    crosstalk_ops = []
    # Identificamos quiénes sufren el "ruido inducido"
    for q in qubits_afectados:
        vecinos = topologia.get(q, [])
        for v in vecinos:
            # Añadimos un error sutil (ej. rotación Z) a los vecinos
            crosstalk_ops.append((RZGate(epsilon_xtalk), [v]))
    return crosstalk_ops


def add_noise(circuit_limpio, epsilon_cx_ch=0.008, epsilon_xtalk=0.002):
    # Creamos un nuevo circuito vacío con los mismos registros
    circuito_ruidoso = QuantumCircuit(*circuit_limpio.qregs, *circuit_limpio.cregs)
    topologia = generar_malla_n_qubits(get_real_qubit_num(circuito_ruidoso))

    # Parámetros del ruido sistemático/coherente (Lo más interesante para simulación exacta)
    epsilon_h_z = 0.005  # Desfase sistemático en H
    epsilon_cp_zz = 0.01  # Error de sobre-rotación en la interacción acoplada de CP
    epsilon_cz_phase = 0.01

    for instruccion, qubits, clbits in circuit_limpio.data:

        # 1. Añadimos la compuerta original de la QFT
        circuito_ruidoso.append(instruccion, qubits, clbits)

        # 2. Inyección de Ruido compatible con Redes de Tensores (Compuertas Unitarias de Ruido)

        if instruccion.name == 'h':
            # El qubit afectado por H sufre una rotación parásita en Z (Error coherente)
            # Esto genera un tensor estándar 2x2 que tu función procesará perfectamente
            compuerta_ruido = RZGate(epsilon_h_z)
            circuito_ruidoso.append(compuerta_ruido, qubits)

        elif instruccion.name == 'cx':
            # En una CX, el qubit de control (qubits[0]) suele sufrir un ligero overshoot de fase (Z)
            # y el qubit target (qubits[1]) sufre una pequeña sobre-rotación de la interacción (X)
            q_control = [qubits[0]]
            q_target = [qubits[1]]
            # Inyectamos rotaciones parásitas microscópicas en ambos qubits involucrados
            circuito_ruidoso.append(RZGate(epsilon_cx_ch), q_control)
            circuito_ruidoso.append(RXGate(epsilon_cx_ch * 0.5), q_target)

        elif instruccion.name == 'cz':
            # La CZ es una compuerta Z controlada.
            # El error físico principal es la fase residual en el control
            # y una sobre-rotación en el target (frecuentemente debida a
            # la interacción electrostática imperfecta).
            q_control = [qubits[0]]
            q_target = [qubits[1]]
            # Inyectamos el error de fase (decalaje) en ambos cúbits
            # para simular la imperfección del pulso de dos cúbits
            circuito_ruidoso.append(RZGate(epsilon_cz_phase), q_control)
            circuito_ruidoso.append(RZGate(epsilon_cz_phase), q_target)

        elif instruccion.name in ['t', 'tdg']:
            # La compuerta T es una rotación RZ(pi/4).
            # El error común es una sobre-rotación o sub-rotación de fase.
            # Introducimos un pequeño error epsilon_t en la rotación Z.
            epsilon_t = 0.002
            circuito_ruidoso.append(RZGate(epsilon_t), qubits)

        elif instruccion.name == 'u':
            # La compuerta U es RZ(phi) * RY(theta) * RZ(lambda).
            # El error es una pequeña imprecisión en los ángulos controlados.
            # Epsilon de error angular para la compuerta general.
            epsilon_u = 0.003

            # Introducimos una rotación parásita combinada para simular
            # la imprecisión en la ejecución del pulso complejo.
            circuito_ruidoso.append(RZGate(epsilon_u), qubits)
            circuito_ruidoso.append(RXGate(epsilon_u), qubits)

        elif instruccion.name == 'p':
            # La compuerta P aplica un desfase en el estado |1>.
            # El error es una sobre-rotación de fase (phi) sistemática.
            epsilon_p = 0.002

            # El error en una compuerta P es casi exclusivamente una fase Z extra.
            circuito_ruidoso.append(RZGate(epsilon_p), qubits)

        elif instruccion.name == 'rz':
            # La compuerta RZ es una rotación RZ(theta).
            # El error es una desviación en el ángulo de rotación debido a
            # la imprecisión en el tiempo de aplicación del pulso o la frecuencia.
            epsilon_rz = 0.001

            # Aplicamos una pequeña sobre-rotación Z
            circuito_ruidoso.append(RZGate(epsilon_rz), qubits)

        elif instruccion.name == 'rx':
            # Rotación en X. Error: pequeña rotación parásita en Y
            epsilon_rx = 0.002
            circuito_ruidoso.append(RXGate(epsilon_rx), qubits)
            circuito_ruidoso.append(RYGate(epsilon_rx * 0.5), qubits)

        elif instruccion.name == 'ry':
            # Rotación en Y. Error: pequeña rotación parásita en X
            epsilon_ry = 0.002
            circuito_ruidoso.append(RYGate(epsilon_ry), qubits)
            circuito_ruidoso.append(RXGate(epsilon_ry * 0.5), qubits)

        elif instruccion.name == 'cp':
            # Para la compuerta CP (dos qubits), el error de calibración física más común
            # es una fase ZZ residual parásita.
            # Lo inyectamos aplicando una pequeña rotación Z en ambos qubits involucrados.
            q_control = [qubits[0]]
            q_target = [qubits[1]]
            circuito_ruidoso.append(RZGate(epsilon_cp_zz), q_control)
            circuito_ruidoso.append(RZGate(epsilon_cp_zz), q_target)

        elif instruccion.name == 'swap':
            # La puerta SWAP se implementa físicamente mediante una secuencia de 3 puertas CX.
            # El ruido aquí es acumulativo: ruido de cada CX + ruido de cross-talk de cada una.
            epsilon_swap = 0.005
            # Aplicamos error en ambos qubits involucrados
            circuito_ruidoso.append(RZGate(epsilon_swap), [qubits[0]])
            circuito_ruidoso.append(RZGate(epsilon_swap), [qubits[1]])

        elif instruccion.name == 'ccx':
            # La puerta Toffoli (CCX) es una de las más costosas y ruidosas.
            # Se descompone en varias puertas H, T, Tdg y CX.
            # Aplicamos un ruido mayor debido a la profundidad lógica del pulso compuesto.
            epsilon_ccx = 0.01
            # Inyección de ruido en los tres qubits participantes (control, control, target)
            for q in qubits:
                circuito_ruidoso.append(RZGate(epsilon_ccx), [q])
                circuito_ruidoso.append(RXGate(epsilon_ccx * 0.5), [q])

        intensidad = 0.00005 * (10 ** len(qubits))

        for q_afectado in qubits:
            for vecino in topologia.get(q_afectado, []):
                circuito_ruidoso.append(RZGate(intensidad), [vecino])

