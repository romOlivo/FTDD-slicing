// Benchmark created by MQT Bench on 2026-06-24
// For more info: https://mqt-bench.app/
// MQT Bench version: 2.2.1
// Qiskit version: 2.1.1
// Output format: qasm3

OPENQASM 3.0;
include "stdgates.inc";
bit[3] bfsm0;
bit[3] pfsm0;
bit[1] m0;
bit[3] bfsm1;
bit[3] pfsm1;
bit[1] m1;
bit[3] bfsm2;
bit[3] pfsm2;
bit[1] m2;
bit[3] bfsm3;
bit[3] pfsm3;
bit[1] m3;
bit[3] bfsm4;
bit[3] pfsm4;
bit[1] m4;
bit[3] bfsm5;
bit[3] pfsm5;
bit[1] m5;
bit[3] bfsm6;
bit[3] pfsm6;
bit[1] m6;
qubit[7] q0;
qubit[3] bfs0;
qubit[3] pfs0;
qubit[7] q1;
qubit[3] bfs1;
qubit[3] pfs1;
qubit[7] q2;
qubit[3] bfs2;
qubit[3] pfs2;
qubit[7] q3;
qubit[3] bfs3;
qubit[3] pfs3;
qubit[7] q4;
qubit[3] bfs4;
qubit[3] pfs4;
qubit[7] q5;
qubit[3] bfs5;
qubit[3] pfs5;
qubit[7] q6;
qubit[3] bfs6;
qubit[3] pfs6;
cx q0[0], q0[1];
cx q0[0], q0[2];
h q0[4];
h q0[5];
h q0[6];
cx q0[6], q0[3];
cx q0[5], q0[3];
cx q0[4], q0[3];
cx q0[5], q0[2];
cx q0[4], q0[2];
cx q0[6], q0[1];
cx q0[4], q0[1];
cx q0[6], q0[0];
cx q0[5], q0[0];
barrier q0[0], q0[1], q0[2], q0[3], q0[4], q0[5], q0[6], bfs0[0], bfs0[1], bfs0[2], pfs0[0], pfs0[1], pfs0[2];
cx q0[0], bfs0[0];
cx q0[1], bfs0[1];
cx q0[2], bfs0[0];
cx q0[2], bfs0[1];
cx q0[3], bfs0[2];
cx q0[4], bfs0[0];
cx q0[4], bfs0[2];
cx q0[5], bfs0[1];
cx q0[5], bfs0[2];
cx q0[6], bfs0[0];
cx q0[6], bfs0[1];
cx q0[6], bfs0[2];
h pfs0[0];
cx pfs0[0], q0[0];
cx pfs0[0], q0[2];
cx pfs0[0], q0[4];
cx pfs0[0], q0[6];
h pfs0[0];
h pfs0[1];
cx pfs0[1], q0[1];
cx pfs0[1], q0[2];
cx pfs0[1], q0[5];
cx pfs0[1], q0[6];
h pfs0[1];
h pfs0[2];
cx pfs0[2], q0[3];
cx pfs0[2], q0[4];
cx pfs0[2], q0[5];
cx pfs0[2], q0[6];
h pfs0[2];
barrier q0[0], q0[1], q0[2], q0[3], q0[4], q0[5], q0[6], bfs0[0], bfs0[1], bfs0[2], pfs0[0], pfs0[1], pfs0[2];
cx q1[0], q1[1];
cx q1[0], q1[2];
h q1[4];
h q1[5];
h q1[6];
cx q1[6], q1[3];
cx q1[5], q1[3];
cx q1[4], q1[3];
cx q1[5], q1[2];
cx q1[4], q1[2];
cx q1[6], q1[1];
cx q1[4], q1[1];
cx q1[6], q1[0];
cx q1[5], q1[0];
barrier q1[0], q1[1], q1[2], q1[3], q1[4], q1[5], q1[6], bfs1[0], bfs1[1], bfs1[2], pfs1[0], pfs1[1], pfs1[2];
cx q1[0], bfs1[0];
cx q1[1], bfs1[1];
cx q1[2], bfs1[0];
cx q1[2], bfs1[1];
cx q1[3], bfs1[2];
cx q1[4], bfs1[0];
cx q1[4], bfs1[2];
cx q1[5], bfs1[1];
cx q1[5], bfs1[2];
cx q1[6], bfs1[0];
cx q1[6], bfs1[1];
cx q1[6], bfs1[2];
h pfs1[0];
cx pfs1[0], q1[0];
cx pfs1[0], q1[2];
cx pfs1[0], q1[4];
cx pfs1[0], q1[6];
h pfs1[0];
h pfs1[1];
cx pfs1[1], q1[1];
cx pfs1[1], q1[2];
cx pfs1[1], q1[5];
cx pfs1[1], q1[6];
h pfs1[1];
h pfs1[2];
cx pfs1[2], q1[3];
cx pfs1[2], q1[4];
cx pfs1[2], q1[5];
cx pfs1[2], q1[6];
h pfs1[2];
barrier q1[0], q1[1], q1[2], q1[3], q1[4], q1[5], q1[6], bfs1[0], bfs1[1], bfs1[2], pfs1[0], pfs1[1], pfs1[2];
cx q2[0], q2[1];
cx q2[0], q2[2];
h q2[4];
h q2[5];
h q2[6];
cx q2[6], q2[3];
cx q2[5], q2[3];
cx q2[4], q2[3];
cx q2[5], q2[2];
cx q2[4], q2[2];
cx q2[6], q2[1];
cx q2[4], q2[1];
cx q2[6], q2[0];
cx q2[5], q2[0];
barrier q2[0], q2[1], q2[2], q2[3], q2[4], q2[5], q2[6], bfs2[0], bfs2[1], bfs2[2], pfs2[0], pfs2[1], pfs2[2];
cx q2[0], bfs2[0];
cx q2[1], bfs2[1];
cx q2[2], bfs2[0];
cx q2[2], bfs2[1];
cx q2[3], bfs2[2];
cx q2[4], bfs2[0];
cx q2[4], bfs2[2];
cx q2[5], bfs2[1];
cx q2[5], bfs2[2];
cx q2[6], bfs2[0];
cx q2[6], bfs2[1];
cx q2[6], bfs2[2];
h pfs2[0];
cx pfs2[0], q2[0];
cx pfs2[0], q2[2];
cx pfs2[0], q2[4];
cx pfs2[0], q2[6];
h pfs2[0];
h pfs2[1];
cx pfs2[1], q2[1];
cx pfs2[1], q2[2];
cx pfs2[1], q2[5];
cx pfs2[1], q2[6];
h pfs2[1];
h pfs2[2];
cx pfs2[2], q2[3];
cx pfs2[2], q2[4];
cx pfs2[2], q2[5];
cx pfs2[2], q2[6];
h pfs2[2];
barrier q2[0], q2[1], q2[2], q2[3], q2[4], q2[5], q2[6], bfs2[0], bfs2[1], bfs2[2], pfs2[0], pfs2[1], pfs2[2];
cx q3[0], q3[1];
cx q3[0], q3[2];
h q3[4];
h q3[5];
h q3[6];
cx q3[6], q3[3];
cx q3[5], q3[3];
cx q3[4], q3[3];
cx q3[5], q3[2];
cx q3[4], q3[2];
cx q3[6], q3[1];
cx q3[4], q3[1];
cx q3[6], q3[0];
cx q3[5], q3[0];
barrier q3[0], q3[1], q3[2], q3[3], q3[4], q3[5], q3[6], bfs3[0], bfs3[1], bfs3[2], pfs3[0], pfs3[1], pfs3[2];
cx q3[0], bfs3[0];
cx q3[1], bfs3[1];
cx q3[2], bfs3[0];
cx q3[2], bfs3[1];
cx q3[3], bfs3[2];
cx q3[4], bfs3[0];
cx q3[4], bfs3[2];
cx q3[5], bfs3[1];
cx q3[5], bfs3[2];
cx q3[6], bfs3[0];
cx q3[6], bfs3[1];
cx q3[6], bfs3[2];
h pfs3[0];
cx pfs3[0], q3[0];
cx pfs3[0], q3[2];
cx pfs3[0], q3[4];
cx pfs3[0], q3[6];
h pfs3[0];
h pfs3[1];
cx pfs3[1], q3[1];
cx pfs3[1], q3[2];
cx pfs3[1], q3[5];
cx pfs3[1], q3[6];
h pfs3[1];
h pfs3[2];
cx pfs3[2], q3[3];
cx pfs3[2], q3[4];
cx pfs3[2], q3[5];
cx pfs3[2], q3[6];
h pfs3[2];
barrier q3[0], q3[1], q3[2], q3[3], q3[4], q3[5], q3[6], bfs3[0], bfs3[1], bfs3[2], pfs3[0], pfs3[1], pfs3[2];
cx q4[0], q4[1];
cx q4[0], q4[2];
h q4[4];
h q4[5];
h q4[6];
cx q4[6], q4[3];
cx q4[5], q4[3];
cx q4[4], q4[3];
cx q4[5], q4[2];
cx q4[4], q4[2];
cx q4[6], q4[1];
cx q4[4], q4[1];
cx q4[6], q4[0];
cx q4[5], q4[0];
barrier q4[0], q4[1], q4[2], q4[3], q4[4], q4[5], q4[6], bfs4[0], bfs4[1], bfs4[2], pfs4[0], pfs4[1], pfs4[2];
cx q4[0], bfs4[0];
cx q4[1], bfs4[1];
cx q4[2], bfs4[0];
cx q4[2], bfs4[1];
cx q4[3], bfs4[2];
cx q4[4], bfs4[0];
cx q4[4], bfs4[2];
cx q4[5], bfs4[1];
cx q4[5], bfs4[2];
cx q4[6], bfs4[0];
cx q4[6], bfs4[1];
cx q4[6], bfs4[2];
h pfs4[0];
cx pfs4[0], q4[0];
cx pfs4[0], q4[2];
cx pfs4[0], q4[4];
cx pfs4[0], q4[6];
h pfs4[0];
h pfs4[1];
cx pfs4[1], q4[1];
cx pfs4[1], q4[2];
cx pfs4[1], q4[5];
cx pfs4[1], q4[6];
h pfs4[1];
h pfs4[2];
cx pfs4[2], q4[3];
cx pfs4[2], q4[4];
cx pfs4[2], q4[5];
cx pfs4[2], q4[6];
h pfs4[2];
barrier q4[0], q4[1], q4[2], q4[3], q4[4], q4[5], q4[6], bfs4[0], bfs4[1], bfs4[2], pfs4[0], pfs4[1], pfs4[2];
cx q5[0], q5[1];
cx q5[0], q5[2];
h q5[4];
h q5[5];
h q5[6];
cx q5[6], q5[3];
cx q5[5], q5[3];
cx q5[4], q5[3];
cx q5[5], q5[2];
cx q5[4], q5[2];
cx q5[6], q5[1];
cx q5[4], q5[1];
cx q5[6], q5[0];
cx q5[5], q5[0];
barrier q5[0], q5[1], q5[2], q5[3], q5[4], q5[5], q5[6], bfs5[0], bfs5[1], bfs5[2], pfs5[0], pfs5[1], pfs5[2];
cx q5[0], bfs5[0];
cx q5[1], bfs5[1];
cx q5[2], bfs5[0];
cx q5[2], bfs5[1];
cx q5[3], bfs5[2];
cx q5[4], bfs5[0];
cx q5[4], bfs5[2];
cx q5[5], bfs5[1];
cx q5[5], bfs5[2];
cx q5[6], bfs5[0];
cx q5[6], bfs5[1];
cx q5[6], bfs5[2];
h pfs5[0];
cx pfs5[0], q5[0];
cx pfs5[0], q5[2];
cx pfs5[0], q5[4];
cx pfs5[0], q5[6];
h pfs5[0];
h pfs5[1];
cx pfs5[1], q5[1];
cx pfs5[1], q5[2];
cx pfs5[1], q5[5];
cx pfs5[1], q5[6];
h pfs5[1];
h pfs5[2];
cx pfs5[2], q5[3];
cx pfs5[2], q5[4];
cx pfs5[2], q5[5];
cx pfs5[2], q5[6];
h pfs5[2];
barrier q5[0], q5[1], q5[2], q5[3], q5[4], q5[5], q5[6], bfs5[0], bfs5[1], bfs5[2], pfs5[0], pfs5[1], pfs5[2];
cx q6[0], q6[1];
cx q6[0], q6[2];
h q6[4];
h q6[5];
h q6[6];
cx q6[6], q6[3];
cx q6[5], q6[3];
cx q6[4], q6[3];
cx q6[5], q6[2];
cx q6[4], q6[2];
cx q6[6], q6[1];
cx q6[4], q6[1];
cx q6[6], q6[0];
cx q6[5], q6[0];
barrier q6[0], q6[1], q6[2], q6[3], q6[4], q6[5], q6[6], bfs6[0], bfs6[1], bfs6[2], pfs6[0], pfs6[1], pfs6[2];
cx q6[0], bfs6[0];
cx q6[1], bfs6[1];
cx q6[2], bfs6[0];
cx q6[2], bfs6[1];
cx q6[3], bfs6[2];
cx q6[4], bfs6[0];
cx q6[4], bfs6[2];
cx q6[5], bfs6[1];
cx q6[5], bfs6[2];
cx q6[6], bfs6[0];
cx q6[6], bfs6[1];
cx q6[6], bfs6[2];
h pfs6[0];
cx pfs6[0], q6[0];
cx pfs6[0], q6[2];
cx pfs6[0], q6[4];
cx pfs6[0], q6[6];
h pfs6[0];
h pfs6[1];
cx pfs6[1], q6[1];
cx pfs6[1], q6[2];
cx pfs6[1], q6[5];
cx pfs6[1], q6[6];
h pfs6[1];
h pfs6[2];
cx pfs6[2], q6[3];
cx pfs6[2], q6[4];
cx pfs6[2], q6[5];
cx pfs6[2], q6[6];
h pfs6[2];
barrier q6[0], q6[1], q6[2], q6[3], q6[4], q6[5], q6[6], bfs6[0], bfs6[1], bfs6[2], pfs6[0], pfs6[1], pfs6[2];
bfsm0[0] = measure bfs0[0];
bfsm0[1] = measure bfs0[1];
bfsm0[2] = measure bfs0[2];
if (bfsm0 == 1) {
  x q0[0];
}
if (bfsm0 == 2) {
  x q0[1];
}
if (bfsm0 == 3) {
  x q0[2];
}
if (bfsm0 == 4) {
  x q0[3];
}
if (bfsm0 == 5) {
  x q0[4];
}
if (bfsm0 == 6) {
  x q0[5];
}
if (bfsm0 == 7) {
  x q0[6];
}
pfsm0[0] = measure pfs0[0];
pfsm0[1] = measure pfs0[1];
pfsm0[2] = measure pfs0[2];
if (pfsm0 == 1) {
  z q0[0];
}
if (pfsm0 == 2) {
  z q0[1];
}
if (pfsm0 == 3) {
  z q0[2];
}
if (pfsm0 == 4) {
  z q0[3];
}
if (pfsm0 == 5) {
  z q0[4];
}
if (pfsm0 == 6) {
  z q0[5];
}
if (pfsm0 == 7) {
  z q0[6];
}
barrier q0[0], q0[1], q0[2], q0[3], q0[4], q0[5], q0[6], bfs0[0], bfs0[1], bfs0[2], pfs0[0], pfs0[1], pfs0[2];
cx q0[4], q0[1];
cx q0[4], q0[2];
cx q0[4], q0[3];
h q0[4];
cx q0[5], q0[0];
cx q0[5], q0[2];
cx q0[5], q0[3];
h q0[5];
cx q0[6], q0[0];
cx q0[0], q0[2];
cx q0[6], q0[1];
cx q0[0], q0[1];
cx q0[6], q0[3];
h q0[6];
m0[0] = measure q0[0];
bfsm1[0] = measure bfs1[0];
bfsm1[1] = measure bfs1[1];
bfsm1[2] = measure bfs1[2];
if (bfsm1 == 1) {
  x q1[0];
}
if (bfsm1 == 2) {
  x q1[1];
}
if (bfsm1 == 3) {
  x q1[2];
}
if (bfsm1 == 4) {
  x q1[3];
}
if (bfsm1 == 5) {
  x q1[4];
}
if (bfsm1 == 6) {
  x q1[5];
}
if (bfsm1 == 7) {
  x q1[6];
}
pfsm1[0] = measure pfs1[0];
pfsm1[1] = measure pfs1[1];
pfsm1[2] = measure pfs1[2];
if (pfsm1 == 1) {
  z q1[0];
}
if (pfsm1 == 2) {
  z q1[1];
}
if (pfsm1 == 3) {
  z q1[2];
}
if (pfsm1 == 4) {
  z q1[3];
}
if (pfsm1 == 5) {
  z q1[4];
}
if (pfsm1 == 6) {
  z q1[5];
}
if (pfsm1 == 7) {
  z q1[6];
}
barrier q1[0], q1[1], q1[2], q1[3], q1[4], q1[5], q1[6], bfs1[0], bfs1[1], bfs1[2], pfs1[0], pfs1[1], pfs1[2];
cx q1[4], q1[1];
cx q1[4], q1[2];
cx q1[4], q1[3];
h q1[4];
cx q1[5], q1[0];
cx q1[5], q1[2];
cx q1[5], q1[3];
h q1[5];
cx q1[6], q1[0];
cx q1[0], q1[2];
cx q1[6], q1[1];
cx q1[0], q1[1];
cx q1[6], q1[3];
h q1[6];
m1[0] = measure q1[0];
bfsm2[0] = measure bfs2[0];
bfsm2[1] = measure bfs2[1];
bfsm2[2] = measure bfs2[2];
if (bfsm2 == 1) {
  x q2[0];
}
if (bfsm2 == 2) {
  x q2[1];
}
if (bfsm2 == 3) {
  x q2[2];
}
if (bfsm2 == 4) {
  x q2[3];
}
if (bfsm2 == 5) {
  x q2[4];
}
if (bfsm2 == 6) {
  x q2[5];
}
if (bfsm2 == 7) {
  x q2[6];
}
pfsm2[0] = measure pfs2[0];
pfsm2[1] = measure pfs2[1];
pfsm2[2] = measure pfs2[2];
if (pfsm2 == 1) {
  z q2[0];
}
if (pfsm2 == 2) {
  z q2[1];
}
if (pfsm2 == 3) {
  z q2[2];
}
if (pfsm2 == 4) {
  z q2[3];
}
if (pfsm2 == 5) {
  z q2[4];
}
if (pfsm2 == 6) {
  z q2[5];
}
if (pfsm2 == 7) {
  z q2[6];
}
barrier q2[0], q2[1], q2[2], q2[3], q2[4], q2[5], q2[6], bfs2[0], bfs2[1], bfs2[2], pfs2[0], pfs2[1], pfs2[2];
cx q2[4], q2[1];
cx q2[4], q2[2];
cx q2[4], q2[3];
h q2[4];
cx q2[5], q2[0];
cx q2[5], q2[2];
cx q2[5], q2[3];
h q2[5];
cx q2[6], q2[0];
cx q2[0], q2[2];
cx q2[6], q2[1];
cx q2[0], q2[1];
cx q2[6], q2[3];
h q2[6];
m2[0] = measure q2[0];
bfsm3[0] = measure bfs3[0];
bfsm3[1] = measure bfs3[1];
bfsm3[2] = measure bfs3[2];
if (bfsm3 == 1) {
  x q3[0];
}
if (bfsm3 == 2) {
  x q3[1];
}
if (bfsm3 == 3) {
  x q3[2];
}
if (bfsm3 == 4) {
  x q3[3];
}
if (bfsm3 == 5) {
  x q3[4];
}
if (bfsm3 == 6) {
  x q3[5];
}
if (bfsm3 == 7) {
  x q3[6];
}
pfsm3[0] = measure pfs3[0];
pfsm3[1] = measure pfs3[1];
pfsm3[2] = measure pfs3[2];
if (pfsm3 == 1) {
  z q3[0];
}
if (pfsm3 == 2) {
  z q3[1];
}
if (pfsm3 == 3) {
  z q3[2];
}
if (pfsm3 == 4) {
  z q3[3];
}
if (pfsm3 == 5) {
  z q3[4];
}
if (pfsm3 == 6) {
  z q3[5];
}
if (pfsm3 == 7) {
  z q3[6];
}
barrier q3[0], q3[1], q3[2], q3[3], q3[4], q3[5], q3[6], bfs3[0], bfs3[1], bfs3[2], pfs3[0], pfs3[1], pfs3[2];
cx q3[4], q3[1];
cx q3[4], q3[2];
cx q3[4], q3[3];
h q3[4];
cx q3[5], q3[0];
cx q3[5], q3[2];
cx q3[5], q3[3];
h q3[5];
cx q3[6], q3[0];
cx q3[0], q3[2];
cx q3[6], q3[1];
cx q3[0], q3[1];
cx q3[6], q3[3];
h q3[6];
m3[0] = measure q3[0];
bfsm4[0] = measure bfs4[0];
bfsm4[1] = measure bfs4[1];
bfsm4[2] = measure bfs4[2];
if (bfsm4 == 1) {
  x q4[0];
}
if (bfsm4 == 2) {
  x q4[1];
}
if (bfsm4 == 3) {
  x q4[2];
}
if (bfsm4 == 4) {
  x q4[3];
}
if (bfsm4 == 5) {
  x q4[4];
}
if (bfsm4 == 6) {
  x q4[5];
}
if (bfsm4 == 7) {
  x q4[6];
}
pfsm4[0] = measure pfs4[0];
pfsm4[1] = measure pfs4[1];
pfsm4[2] = measure pfs4[2];
if (pfsm4 == 1) {
  z q4[0];
}
if (pfsm4 == 2) {
  z q4[1];
}
if (pfsm4 == 3) {
  z q4[2];
}
if (pfsm4 == 4) {
  z q4[3];
}
if (pfsm4 == 5) {
  z q4[4];
}
if (pfsm4 == 6) {
  z q4[5];
}
if (pfsm4 == 7) {
  z q4[6];
}
barrier q4[0], q4[1], q4[2], q4[3], q4[4], q4[5], q4[6], bfs4[0], bfs4[1], bfs4[2], pfs4[0], pfs4[1], pfs4[2];
cx q4[4], q4[1];
cx q4[4], q4[2];
cx q4[4], q4[3];
h q4[4];
cx q4[5], q4[0];
cx q4[5], q4[2];
cx q4[5], q4[3];
h q4[5];
cx q4[6], q4[0];
cx q4[0], q4[2];
cx q4[6], q4[1];
cx q4[0], q4[1];
cx q4[6], q4[3];
h q4[6];
m4[0] = measure q4[0];
bfsm5[0] = measure bfs5[0];
bfsm5[1] = measure bfs5[1];
bfsm5[2] = measure bfs5[2];
if (bfsm5 == 1) {
  x q5[0];
}
if (bfsm5 == 2) {
  x q5[1];
}
if (bfsm5 == 3) {
  x q5[2];
}
if (bfsm5 == 4) {
  x q5[3];
}
if (bfsm5 == 5) {
  x q5[4];
}
if (bfsm5 == 6) {
  x q5[5];
}
if (bfsm5 == 7) {
  x q5[6];
}
pfsm5[0] = measure pfs5[0];
pfsm5[1] = measure pfs5[1];
pfsm5[2] = measure pfs5[2];
if (pfsm5 == 1) {
  z q5[0];
}
if (pfsm5 == 2) {
  z q5[1];
}
if (pfsm5 == 3) {
  z q5[2];
}
if (pfsm5 == 4) {
  z q5[3];
}
if (pfsm5 == 5) {
  z q5[4];
}
if (pfsm5 == 6) {
  z q5[5];
}
if (pfsm5 == 7) {
  z q5[6];
}
barrier q5[0], q5[1], q5[2], q5[3], q5[4], q5[5], q5[6], bfs5[0], bfs5[1], bfs5[2], pfs5[0], pfs5[1], pfs5[2];
cx q5[4], q5[1];
cx q5[4], q5[2];
cx q5[4], q5[3];
h q5[4];
cx q5[5], q5[0];
cx q5[5], q5[2];
cx q5[5], q5[3];
h q5[5];
cx q5[6], q5[0];
cx q5[0], q5[2];
cx q5[6], q5[1];
cx q5[0], q5[1];
cx q5[6], q5[3];
h q5[6];
m5[0] = measure q5[0];
bfsm6[0] = measure bfs6[0];
bfsm6[1] = measure bfs6[1];
bfsm6[2] = measure bfs6[2];
if (bfsm6 == 1) {
  x q6[0];
}
if (bfsm6 == 2) {
  x q6[1];
}
if (bfsm6 == 3) {
  x q6[2];
}
if (bfsm6 == 4) {
  x q6[3];
}
if (bfsm6 == 5) {
  x q6[4];
}
if (bfsm6 == 6) {
  x q6[5];
}
if (bfsm6 == 7) {
  x q6[6];
}
pfsm6[0] = measure pfs6[0];
pfsm6[1] = measure pfs6[1];
pfsm6[2] = measure pfs6[2];
if (pfsm6 == 1) {
  z q6[0];
}
if (pfsm6 == 2) {
  z q6[1];
}
if (pfsm6 == 3) {
  z q6[2];
}
if (pfsm6 == 4) {
  z q6[3];
}
if (pfsm6 == 5) {
  z q6[4];
}
if (pfsm6 == 6) {
  z q6[5];
}
if (pfsm6 == 7) {
  z q6[6];
}
barrier q6[0], q6[1], q6[2], q6[3], q6[4], q6[5], q6[6], bfs6[0], bfs6[1], bfs6[2], pfs6[0], pfs6[1], pfs6[2];
cx q6[4], q6[1];
cx q6[4], q6[2];
cx q6[4], q6[3];
h q6[4];
cx q6[5], q6[0];
cx q6[5], q6[2];
cx q6[5], q6[3];
h q6[5];
cx q6[6], q6[0];
cx q6[0], q6[2];
cx q6[6], q6[1];
cx q6[0], q6[1];
cx q6[6], q6[3];
h q6[6];
m6[0] = measure q6[0];
barrier q0[0], q0[1], q0[2], q0[3], q0[4], q0[5], q0[6], bfs0[0], bfs0[1], bfs0[2], pfs0[0], pfs0[1], pfs0[2], q1[0], q1[1], q1[2], q1[3], q1[4], q1[5], q1[6], bfs1[0], bfs1[1], bfs1[2], pfs1[0], pfs1[1], pfs1[2], q2[0], q2[1], q2[2], q2[3], q2[4], q2[5], q2[6], bfs2[0], bfs2[1], bfs2[2], pfs2[0], pfs2[1], pfs2[2], q3[0], q3[1], q3[2], q3[3], q3[4], q3[5], q3[6], bfs3[0], bfs3[1], bfs3[2], pfs3[0], pfs3[1], pfs3[2], q4[0], q4[1], q4[2], q4[3], q4[4], q4[5], q4[6], bfs4[0], bfs4[1], bfs4[2], pfs4[0], pfs4[1], pfs4[2], q5[0], q5[1], q5[2], q5[3], q5[4], q5[5], q5[6], bfs5[0], bfs5[1], bfs5[2], pfs5[0], pfs5[1], pfs5[2], q6[0], q6[1], q6[2], q6[3], q6[4], q6[5], q6[6], bfs6[0], bfs6[1], bfs6[2], pfs6[0], pfs6[1], pfs6[2];
