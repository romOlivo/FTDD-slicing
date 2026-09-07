"""

    This file was created and documented by Vicente Lopez (voliva@uji.es, @voliva-esp) for testing purposes.

"""

import source.cpp.build.cTDD as cTDD
import unittest
from qiskit import QuantumCircuit
from source.Simulate import PyTN_2_cTN
from source.TDD import Ini_TDD
from source.TDD_Q import cir_2_tn_lbl, get_real_qubit_num, squeezeTN, squeezeTN_ultra, add_inputs
from source.TN import TensorNetwork, tdd_to_tensor
import numpy as np


def init_and_simulate(circuit : QuantumCircuit):
    tn_lbl, all_indexs_lbl, depth = cir_2_tn_lbl(circuit)
    n = get_real_qubit_num(circuit)

    tensors_tetris = squeezeTN(tn_lbl.tensors, n, depth)
    tensors_tetris = squeezeTN_ultra(tensors_tetris, n, depth)
    tn_tetris = TensorNetwork(tensors_tetris, tn_lbl.tn_type, n)
    input_s = [0] * n
    add_inputs(tn_tetris, input_s, n)
    path = tn_tetris.get_seq_path()

    n_bucket = 32000
    initial_gc_limit = 20
    initial_gc_lur = 0.9
    act_bucket = 32768
    cct_bucket = 32768
    uniqTabConfig = [initial_gc_limit, initial_gc_lur, n_bucket, act_bucket, cct_bucket]

    cTDD.Ini_TDD(all_indexs_lbl, uniqTabConfig, False)
    Ini_TDD(all_indexs_lbl)

    cTN = PyTN_2_cTN(tn_tetris)
    ptdd = tn_tetris.cont_TN(path, False)
    ctdd = cTN.cont_TN(path, False)

    return ptdd, ctdd

def calculate_fidelity(ptdd, ctdd):
    ptdd_ToTensor = np.transpose(ptdd.to_array())
    ctdd_ToTensor = tdd_to_tensor(ctdd.to_array(), ptdd.index_set)
    return np.abs(np.inner(ptdd_ToTensor.flatten(), ctdd_ToTensor.flatten().conj()))

class TestFidelity(unittest.TestCase):
    """
        Suite designed to test the fidelity results between FTDD and PyTDD
    """

    def test_fidelity_qft(self):
        path = "./Benchmarks/Verification/qft_9.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        ptdd, ctdd = init_and_simulate(circuit)
        fidelity = calculate_fidelity(ptdd, ctdd)
        self.assertAlmostEqual(fidelity, 1)

    def test_fidelity_qgan(self):
        path = "./Benchmarks/Verification/qgan_indep_qiskit_6.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        ptdd, ctdd = init_and_simulate(circuit)
        fidelity = calculate_fidelity(ptdd, ctdd)
        self.assertAlmostEqual(fidelity, 1)

    def test_fidelity_qwalk(self):
        path = "./Benchmarks/Verification/qwalk2_noancilla_n05_depth01_compiled.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        ptdd, ctdd = init_and_simulate(circuit)
        fidelity = calculate_fidelity(ptdd, ctdd)
        self.assertAlmostEqual(fidelity, 1)

    def test_fidelity_qnn(self):
        path = "./Benchmarks/Verification/qnn_indep_qiskit_11.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        ptdd, ctdd = init_and_simulate(circuit)
        fidelity = calculate_fidelity(ptdd, ctdd)
        self.assertAlmostEqual(fidelity, 1)

    def test_fidelity_vqe(self):
        path = "./Benchmarks/Verification/vqe_1dhm_10.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        ptdd, ctdd = init_and_simulate(circuit)
        fidelity = calculate_fidelity(ptdd, ctdd)
        self.assertAlmostEqual(fidelity, 1)

