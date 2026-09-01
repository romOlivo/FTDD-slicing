"""

    This file was created and documented by Vicente Lopez (voliva@uji.es, @voliva-esp) for testing purposes.

"""

import unittest
import source.cpp.build.cTDD as cTDD

def init():
    n_bucket = 32000
    initial_gc_limit = 20
    initial_gc_lur = 0.9
    act_bucket = 32768
    cct_bucket = 32768
    uniqTabConfig = [initial_gc_limit, initial_gc_lur, n_bucket, act_bucket, cct_bucket]

    cTDD.Ini_TDD([], uniqTabConfig, False)

class TestAddFetdd(unittest.TestCase):
    """
        Suite designed to testing the method 'add' of the cTDD.cpp file

        In the 'same' tests, we generate only one TDD and add two of them.
        In the 'different' tests, we generate 2 TDDs and sum them up.
    """

    def test_add_simple_edge_different_fetdd(self):
        edge1 = cTDD.Edge()
        edge1.weight = 2
        edge2 = cTDD.Edge()
        edge2.weight = 1
        res_edge = cTDD.add(edge1, edge2)

        self.assertEqual(3, res_edge.weight)

    def test_add_simple_tdd_different_fetdd(self):
        edge1 = cTDD.Edge()
        edge1.weight = 1
        tdd1 = cTDD.TDD(edge1)
        edge2 = cTDD.Edge()
        edge2.weight = 2
        tdd2 = cTDD.TDD(edge2)
        res_edge = cTDD.add(tdd1.root, tdd2.root)

        self.assertEqual(3, res_edge.weight)

    def test_add_simple_edge_same_fetdd(self):
        edge1 = cTDD.Edge()
        edge1.weight = 1
        res_edge = cTDD.add(edge1, edge1)

        self.assertEqual(2, res_edge.weight)

    def test_add_simple_tdd_same_fetdd(self):
        edge1 = cTDD.Edge()
        edge1.weight = 1
        tdd1 = cTDD.TDD(edge1)
        res_edge = cTDD.add(tdd1.root, tdd1.root)

        self.assertEqual(2, res_edge.weight)

    def test_add_1L_simple_edge_different(self):
        init()
        node_common = cTDD.Node()
        node_common.key = -1
        edge_common = cTDD.Edge()
        edge_common.weight = 1
        edge_common.node = node_common
        node_1 = cTDD.Node()
        node_1.key = 0
        node_1.edges = [edge_common, edge_common]
        edge_1 = cTDD.Edge()
        edge_1.weight = 1
        edge_1.node = node_1
        edge_2 = cTDD.Edge()
        edge_2.weight = 2
        edge_2.node = node_1
        res_edge = cTDD.add(edge_1, edge_2)

        self.assertEqual(3, res_edge.weight)
        self.assertEqual(0, res_edge.node.key)

    def test_add_1L_simple_edge_same(self):
        init()
        node_common = cTDD.Node()
        node_common.key = -1
        edge_common = cTDD.Edge()
        edge_common.weight = 1
        edge_common.node = node_common
        node_1 = cTDD.Node()
        node_1.key = 0
        node_1.edges = [edge_common, edge_common]
        edge_1 = cTDD.Edge()
        edge_1.weight = 1
        edge_1.node = node_1
        res_edge = cTDD.add(edge_1, edge_1)

        self.assertEqual(2, res_edge.weight)
        self.assertEqual(0, res_edge.node.key)

    def test_add_1L_unbalance_edge_different(self):
        init()
        node_common = cTDD.Node()
        node_common.key = -1
        edge_one = cTDD.Edge()
        edge_one.weight = 1
        edge_one.node = node_common
        edge_two = cTDD.Edge()
        edge_two.weight = 2
        edge_two.node = node_common
        edge_zero = cTDD.Edge()
        edge_zero.weight = 0
        edge_zero.node = node_common
        node_1 = cTDD.Node()
        node_1.key = 0
        node_1.edges = [edge_two, edge_zero]
        node_2 = cTDD.Node()
        node_2.key = 0
        node_2.edges = [edge_zero, edge_one]
        edge_1 = cTDD.Edge()
        edge_1.weight = 1
        edge_1.node = node_1
        edge_2 = cTDD.Edge()
        edge_2.weight = 1
        edge_2.node = node_2
        res_edge = cTDD.add(edge_1, edge_2)

        self.assertEqual(2, res_edge.weight)
        self.assertEqual(0, res_edge.node.key)
        self.assertEqual(1, res_edge.node.edges[0].weight)
        self.assertEqual(0.5, res_edge.node.edges[1].weight)

