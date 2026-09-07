"""

    This file was created and documented by Vicente Lopez (voliva@uji.es, @romOlivo) for testing purposes.

"""
from qiskit import QuantumCircuit

from source.Simulate import simulate, get_statevector
from qiskit.quantum_info import Statevector
import source.cpp.build.cTDD as cTDD
import numpy as np
import unittest


class TestFTDD(unittest.TestCase):
    def test_equivalence_ftdd_close_open_nt_od_pd_statevector_qft(self):
        path = "./Benchmarks/Verification/qft_9.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        result = simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                          index_order_method="default", use_tetris=False, contraction_method="seq")
        self.assertTrue(Statevector(circuit).equiv(Statevector(get_statevector(result, 9))))

    def test_equivalence_ftdd_close_open_t_od_pd_statevector_qft(self):
        path = "./Benchmarks/Verification/qft_9.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        result = simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                          index_order_method="default", use_tetris=True, contraction_method="seq")
        self.assertTrue(Statevector(circuit).equiv(Statevector(get_statevector(result, 9))))

    def test_equivalence_ftdd_close_open_nt_od_pd_statevector_qgan(self):
        path = "./Benchmarks/Verification/qgan_indep_qiskit_6.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        result = simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                          index_order_method="default", use_tetris=False, contraction_method="seq")
        self.assertTrue(Statevector(circuit).equiv(Statevector(get_statevector(result, 6))))

    def test_equivalence_ftdd_close_open_t_od_pd_statevector_qgan(self):
        path = "./Benchmarks/Verification/qgan_indep_qiskit_6.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        result = simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                          index_order_method="default", use_tetris=True, contraction_method="seq")
        self.assertTrue(Statevector(circuit).equiv(Statevector(get_statevector(result, 6))))

    def test_equivalence_ftdd_close_open_nt_od_pd_statevector_qwalk(self):
        path = "./Benchmarks/Verification/qwalk2_noancilla_n05_depth01_compiled.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        result = simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                          index_order_method="default", use_tetris=False, contraction_method="seq")
        self.assertTrue(Statevector(circuit).equiv(Statevector(get_statevector(result, 5))))

    def test_equivalence_ftdd_close_open_t_od_pd_statevector_qwalk(self):
        path = "./Benchmarks/Verification/qwalk2_noancilla_n05_depth01_compiled.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        result = simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                          index_order_method="default", use_tetris=True, contraction_method="seq")
        self.assertTrue(Statevector(circuit).equiv(Statevector(get_statevector(result, 5))))

    def test_equivalence_ftdd_close_open_nt_od_pd_statevector_qnn(self):
        path = "./Benchmarks/Verification/qnn_indep_qiskit_11.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        result = simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                          index_order_method="default", use_tetris=False, contraction_method="seq")
        self.assertTrue(Statevector(circuit).equiv(Statevector(get_statevector(result, 11))))

    def test_equivalence_ftdd_close_open_t_od_pd_statevector_qnn(self):
        path = "./Benchmarks/Verification/qnn_indep_qiskit_11.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        result = simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                          index_order_method="default", use_tetris=True, contraction_method="seq")
        self.assertTrue(Statevector(circuit).equiv(Statevector(get_statevector(result, 11))))

    def test_equivalence_ftdd_close_open_nt_od_pd_statevector_vqe10(self):
        path = "./Benchmarks/Verification/vqe_1dhm_10.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        result = simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                          index_order_method="default", use_tetris=False, contraction_method="seq")
        np.testing.assert_allclose(Statevector(circuit), Statevector(get_statevector(result, 10)), atol=1e-8)

    def test_equivalence_ftdd_close_open_t_od_pd_statevector_vqe10(self):
        path = "./Benchmarks/Verification/vqe_1dhm_10.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        result = simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                          index_order_method="default", use_tetris=True, contraction_method="seq")
        np.testing.assert_allclose(Statevector(circuit), Statevector(get_statevector(result, 10)), atol=1e-8)

    def test_equivalence_ftdd_rep1_fi_close_open_t_op_pko_statevector_vqe10(self):
        path = "./Benchmarks/Verification/vqe_1dhm_10.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                 index_order_method="default", use_tetris=True, contraction_method="k-ops", force_init=True)
        result = simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                          index_order_method="default", use_tetris=True, contraction_method="k-ops", force_init=True)
        np.testing.assert_allclose(Statevector(circuit), Statevector(get_statevector(result, 10)), atol=1e-8)

    def test_equivalence_ftdd_rep2_fi_close_open_t_op_pko_statevector_vqe10(self):
        path = "./Benchmarks/Verification/vqe_1dhm_10.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        N = 2
        for _ in range(N):
            simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                     index_order_method="default", use_tetris=True, contraction_method="k-ops", force_init=True)
        result = simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                          index_order_method="default", use_tetris=True, contraction_method="k-ops", force_init=True)
        np.testing.assert_allclose(Statevector(circuit), Statevector(get_statevector(result, 10)), atol=1e-8)

    def test_equivalence_ftdd_rep4_fi_close_open_t_op_pko_statevector_vqe10(self):
        path = "./Benchmarks/Verification/vqe_1dhm_10.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        N = 4
        for _ in range(N):
            simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                     index_order_method="default", use_tetris=True, contraction_method="k-ops", force_init=True)
        result = simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                          index_order_method="default", use_tetris=True, contraction_method="k-ops", force_init=True)
        np.testing.assert_allclose(Statevector(circuit), Statevector(get_statevector(result, 10)), atol=1e-8)

    """
    def test_equivalence_ftdd_close_open_nt_od_pd_statevector_vqe16(self):
        path = "./Benchmarks/Verification/vqe_1dhm_16.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        result = simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                          index_order_method="default", use_tetris=False, contraction_method="seq")
        np.testing.assert_allclose(Statevector(circuit), Statevector(get_statevector(result, 16)), atol=1e-8)

    def test_equivalence_ftdd_close_open_t_od_pd_statevector_vqe16(self):
        path = "./Benchmarks/Verification/vqe_1dhm_16.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        result = simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                          index_order_method="default", use_tetris=True, contraction_method="seq")
        np.testing.assert_allclose(Statevector(circuit), Statevector(get_statevector(result, 16)), atol=1e-8)

    def test_equivalence_ftdd_close_open_nt_op_pd_statevector_vqe16(self):
        path = "./Benchmarks/Verification/vqe_1dhm_16.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        result = simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                          index_order_method="default", use_tetris=False, contraction_method="seq")
        np.testing.assert_allclose(Statevector(circuit), Statevector(get_statevector(result, 16)), atol=1e-8)

    def test_equivalence_ftdd_close_open_t_op_pd_statevector_vqe16(self):
        path = "./Benchmarks/Verification/vqe_1dhm_16.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        result = simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                          index_order_method="default", use_tetris=True, contraction_method="seq")
        np.testing.assert_allclose(Statevector(circuit), Statevector(get_statevector(result, 16)), atol=1e-8)

    def test_equivalence_ftdd_close_open_nt_od_pko_statevector_vqe16(self):
        path = "./Benchmarks/Verification/vqe_1dhm_16.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        result = simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                          index_order_method="default", use_tetris=False, contraction_method="k-ops")
        np.testing.assert_allclose(Statevector(circuit), Statevector(get_statevector(result, 16)), atol=1e-8)

    def test_equivalence_ftdd_close_open_t_od_pko_statevector_vqe16(self):
        path = "./Benchmarks/Verification/vqe_1dhm_16.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        result = simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                          index_order_method="default", use_tetris=True, contraction_method="k-ops")
        np.testing.assert_allclose(Statevector(circuit), Statevector(get_statevector(result, 16)), atol=1e-8)

    def test_equivalence_ftdd_close_open_nt_op_pko_statevector_vqe16(self):
        path = "./Benchmarks/Verification/vqe_1dhm_16.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        result = simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                          index_order_method="default", use_tetris=False, contraction_method="k-ops")
        np.testing.assert_allclose(Statevector(circuit), Statevector(get_statevector(result, 16)), atol=1e-8)

    def test_equivalence_ftdd_close_open_t_op_pko_statevector_vqe16(self):
        path = "./Benchmarks/Verification/vqe_1dhm_16.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        result = simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                          index_order_method="default", use_tetris=True, contraction_method="k-ops")
        np.testing.assert_allclose(Statevector(circuit), Statevector(get_statevector(result, 16)), atol=1e-8)

    def test_equivalence_ftdd_rep1_close_open_t_op_pko_statevector_vqe16(self):
        path = "./Benchmarks/Verification/vqe_1dhm_16.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        N = 1
        for i in range(N):
            simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                     index_order_method="default", use_tetris=True, contraction_method="k-ops")
        result = simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                          index_order_method="default", use_tetris=True, contraction_method="k-ops")
        np.testing.assert_allclose(Statevector(circuit), Statevector(get_statevector(result, 16)), atol=1e-8)

    def test_equivalence_ftdd_rep2_close_open_t_op_pko_statevector_vqe16(self):
        path = "./Benchmarks/Verification/vqe_1dhm_16.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        N = 2
        for i in range(N):
            simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                     index_order_method="default", use_tetris=True, contraction_method="k-ops")
        result = simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                          index_order_method="default", use_tetris=True, contraction_method="k-ops")
        np.testing.assert_allclose(Statevector(circuit), Statevector(get_statevector(result, 16)), atol=1e-8)

    def test_equivalence_ftdd_rep3_close_open_t_op_pko_statevector_vqe16(self):
        path = "./Benchmarks/Verification/vqe_1dhm_16.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        N = 3
        for i in range(N):
            simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                     index_order_method="default", use_tetris=True, contraction_method="k-ops")
        result = simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                          index_order_method="default", use_tetris=True, contraction_method="k-ops")
        np.testing.assert_allclose(Statevector(circuit), Statevector(get_statevector(result, 16)), atol=1e-8)

    def test_equivalence_ftdd_rep4_close_open_t_op_pko_statevector_vqe16(self):
        path = "./Benchmarks/Verification/vqe_1dhm_16.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        N = 4
        for i in range(N):
            simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                     index_order_method="default", use_tetris=True, contraction_method="k-ops")
        result = simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                          index_order_method="default", use_tetris=True, contraction_method="k-ops")
        np.testing.assert_allclose(Statevector(circuit), Statevector(get_statevector(result, 16)), atol=1e-8)

    def test_equivalence_ftdd_rep5_close_open_t_op_pko_statevector_vqe16(self):
        path = "./Benchmarks/Verification/vqe_1dhm_16.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        N = 5
        for i in range(N):
            simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                     index_order_method="default", use_tetris=True, contraction_method="k-ops")
        result = simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                          index_order_method="default", use_tetris=True, contraction_method="k-ops")
        np.testing.assert_allclose(Statevector(circuit), Statevector(get_statevector(result, 16)), atol=1e-8)

    def test_equivalence_ftdd_rep6_close_open_t_op_pko_statevector_vqe16(self):
        path = "./Benchmarks/Verification/vqe_1dhm_16.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        N = 6
        for i in range(N):
            simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                     index_order_method="default", use_tetris=True, contraction_method="k-ops")
        result = simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                          index_order_method="default", use_tetris=True, contraction_method="k-ops")
        np.testing.assert_allclose(Statevector(circuit), Statevector(get_statevector(result, 16)), atol=1e-8)

    def test_equivalence_ftdd_rep7_close_open_t_op_pko_statevector_vqe16(self):
        path = "./Benchmarks/Verification/vqe_1dhm_16.qasm"
        circuit = QuantumCircuit.from_qasm_file(path)
        N = 7
        for i in range(N):
            simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                     index_order_method="default", use_tetris=True, contraction_method="k-ops")
        result = simulate(circuit, backend="FTDD", is_input_closed=True, is_output_closed=False, handler_name="none",
                          index_order_method="default", use_tetris=True, contraction_method="k-ops")
        np.testing.assert_allclose(Statevector(circuit), Statevector(get_statevector(result, 16)), atol=1e-8)
    """
