// Benchmark created by MQT Bench on 2026-06-24
// For more info: https://mqt-bench.app/
// MQT Bench version: 2.2.1
// Qiskit version: 2.1.1
// Output format: qasm3

OPENQASM 3.0;
include "stdgates.inc";
bit[6] bsm0;
bit[2] psm0;
bit[1] m0;
bit[6] bsm1;
bit[2] psm1;
bit[1] m1;
bit[6] bsm2;
bit[2] psm2;
bit[1] m2;
bit[6] bsm3;
bit[2] psm3;
bit[1] m3;
bit[6] bsm4;
bit[2] psm4;
bit[1] m4;
qubit[9] q0;
qubit[6] bs0;
qubit[2] ps0;
qubit[9] q1;
qubit[6] bs1;
qubit[2] ps1;
qubit[9] q2;
qubit[6] bs2;
qubit[2] ps2;
qubit[9] q3;
qubit[6] bs3;
qubit[2] ps3;
qubit[9] q4;
qubit[6] bs4;
qubit[2] ps4;
cx q0[0], q0[3];
h q0[3];
cx q0[3], q0[4];
cx q0[3], q0[5];
cx q0[0], q0[6];
h q0[0];
cx q0[0], q0[1];
cx q0[0], q0[2];
h q0[6];
cx q0[6], q0[7];
cx q0[6], q0[8];
barrier q0[0], q0[1], q0[2], q0[3], q0[4], q0[5], q0[6], q0[7], q0[8], bs0[0], bs0[1], bs0[2], bs0[3], bs0[4], bs0[5], ps0[0], ps0[1];
cx q0[0], bs0[0];
cx q0[1], bs0[1];
cx q0[2], bs0[0];
cx q0[2], bs0[1];
cx q0[3], bs0[2];
cx q0[4], bs0[3];
cx q0[5], bs0[2];
cx q0[5], bs0[3];
cx q0[6], bs0[4];
cx q0[7], bs0[5];
cx q0[8], bs0[4];
cx q0[8], bs0[5];
barrier q0[0], q0[1], q0[2], q0[3], q0[4], q0[5], q0[6], q0[7], q0[8], bs0[0], bs0[1], bs0[2], bs0[3], bs0[4], bs0[5], ps0[0], ps0[1];
h ps0[0];
cx ps0[0], q0[0];
cx ps0[0], q0[1];
cx ps0[0], q0[2];
cx ps0[0], q0[6];
cx ps0[0], q0[7];
cx ps0[0], q0[8];
h ps0[0];
h ps0[1];
cx ps0[1], q0[3];
cx ps0[1], q0[4];
cx ps0[1], q0[5];
cx ps0[1], q0[6];
cx ps0[1], q0[7];
cx ps0[1], q0[8];
h ps0[1];
barrier q0[0], q0[1], q0[2], q0[3], q0[4], q0[5], q0[6], q0[7], q0[8], bs0[0], bs0[1], bs0[2], bs0[3], bs0[4], bs0[5], ps0[0], ps0[1];
cx q1[0], q1[3];
h q1[3];
cx q1[3], q1[4];
cx q1[3], q1[5];
cx q1[0], q1[6];
h q1[0];
cx q1[0], q1[1];
cx q1[0], q1[2];
h q1[6];
cx q1[6], q1[7];
cx q1[6], q1[8];
barrier q1[0], q1[1], q1[2], q1[3], q1[4], q1[5], q1[6], q1[7], q1[8], bs1[0], bs1[1], bs1[2], bs1[3], bs1[4], bs1[5], ps1[0], ps1[1];
cx q1[0], bs1[0];
cx q1[1], bs1[1];
cx q1[2], bs1[0];
cx q1[2], bs1[1];
cx q1[3], bs1[2];
cx q1[4], bs1[3];
cx q1[5], bs1[2];
cx q1[5], bs1[3];
cx q1[6], bs1[4];
cx q1[7], bs1[5];
cx q1[8], bs1[4];
cx q1[8], bs1[5];
barrier q1[0], q1[1], q1[2], q1[3], q1[4], q1[5], q1[6], q1[7], q1[8], bs1[0], bs1[1], bs1[2], bs1[3], bs1[4], bs1[5], ps1[0], ps1[1];
h ps1[0];
cx ps1[0], q1[0];
cx ps1[0], q1[1];
cx ps1[0], q1[2];
cx ps1[0], q1[6];
cx ps1[0], q1[7];
cx ps1[0], q1[8];
h ps1[0];
h ps1[1];
cx ps1[1], q1[3];
cx ps1[1], q1[4];
cx ps1[1], q1[5];
cx ps1[1], q1[6];
cx ps1[1], q1[7];
cx ps1[1], q1[8];
h ps1[1];
barrier q1[0], q1[1], q1[2], q1[3], q1[4], q1[5], q1[6], q1[7], q1[8], bs1[0], bs1[1], bs1[2], bs1[3], bs1[4], bs1[5], ps1[0], ps1[1];
cx q2[0], q2[3];
h q2[3];
cx q2[3], q2[4];
cx q2[3], q2[5];
cx q2[0], q2[6];
h q2[0];
cx q2[0], q2[1];
cx q2[0], q2[2];
h q2[6];
cx q2[6], q2[7];
cx q2[6], q2[8];
barrier q2[0], q2[1], q2[2], q2[3], q2[4], q2[5], q2[6], q2[7], q2[8], bs2[0], bs2[1], bs2[2], bs2[3], bs2[4], bs2[5], ps2[0], ps2[1];
cx q2[0], bs2[0];
cx q2[1], bs2[1];
cx q2[2], bs2[0];
cx q2[2], bs2[1];
cx q2[3], bs2[2];
cx q2[4], bs2[3];
cx q2[5], bs2[2];
cx q2[5], bs2[3];
cx q2[6], bs2[4];
cx q2[7], bs2[5];
cx q2[8], bs2[4];
cx q2[8], bs2[5];
barrier q2[0], q2[1], q2[2], q2[3], q2[4], q2[5], q2[6], q2[7], q2[8], bs2[0], bs2[1], bs2[2], bs2[3], bs2[4], bs2[5], ps2[0], ps2[1];
h ps2[0];
cx ps2[0], q2[0];
cx ps2[0], q2[1];
cx ps2[0], q2[2];
cx ps2[0], q2[6];
cx ps2[0], q2[7];
cx ps2[0], q2[8];
h ps2[0];
h ps2[1];
cx ps2[1], q2[3];
cx ps2[1], q2[4];
cx ps2[1], q2[5];
cx ps2[1], q2[6];
cx ps2[1], q2[7];
cx ps2[1], q2[8];
h ps2[1];
barrier q2[0], q2[1], q2[2], q2[3], q2[4], q2[5], q2[6], q2[7], q2[8], bs2[0], bs2[1], bs2[2], bs2[3], bs2[4], bs2[5], ps2[0], ps2[1];
cx q3[0], q3[3];
h q3[3];
cx q3[3], q3[4];
cx q3[3], q3[5];
cx q3[0], q3[6];
h q3[0];
cx q3[0], q3[1];
cx q3[0], q3[2];
h q3[6];
cx q3[6], q3[7];
cx q3[6], q3[8];
barrier q3[0], q3[1], q3[2], q3[3], q3[4], q3[5], q3[6], q3[7], q3[8], bs3[0], bs3[1], bs3[2], bs3[3], bs3[4], bs3[5], ps3[0], ps3[1];
cx q3[0], bs3[0];
cx q3[1], bs3[1];
cx q3[2], bs3[0];
cx q3[2], bs3[1];
cx q3[3], bs3[2];
cx q3[4], bs3[3];
cx q3[5], bs3[2];
cx q3[5], bs3[3];
cx q3[6], bs3[4];
cx q3[7], bs3[5];
cx q3[8], bs3[4];
cx q3[8], bs3[5];
barrier q3[0], q3[1], q3[2], q3[3], q3[4], q3[5], q3[6], q3[7], q3[8], bs3[0], bs3[1], bs3[2], bs3[3], bs3[4], bs3[5], ps3[0], ps3[1];
h ps3[0];
cx ps3[0], q3[0];
cx ps3[0], q3[1];
cx ps3[0], q3[2];
cx ps3[0], q3[6];
cx ps3[0], q3[7];
cx ps3[0], q3[8];
h ps3[0];
h ps3[1];
cx ps3[1], q3[3];
cx ps3[1], q3[4];
cx ps3[1], q3[5];
cx ps3[1], q3[6];
cx ps3[1], q3[7];
cx ps3[1], q3[8];
h ps3[1];
barrier q3[0], q3[1], q3[2], q3[3], q3[4], q3[5], q3[6], q3[7], q3[8], bs3[0], bs3[1], bs3[2], bs3[3], bs3[4], bs3[5], ps3[0], ps3[1];
cx q4[0], q4[3];
h q4[3];
cx q4[3], q4[4];
cx q4[3], q4[5];
cx q4[0], q4[6];
h q4[0];
cx q4[0], q4[1];
cx q4[0], q4[2];
h q4[6];
cx q4[6], q4[7];
cx q4[6], q4[8];
barrier q4[0], q4[1], q4[2], q4[3], q4[4], q4[5], q4[6], q4[7], q4[8], bs4[0], bs4[1], bs4[2], bs4[3], bs4[4], bs4[5], ps4[0], ps4[1];
cx q4[0], bs4[0];
cx q4[1], bs4[1];
cx q4[2], bs4[0];
cx q4[2], bs4[1];
cx q4[3], bs4[2];
cx q4[4], bs4[3];
cx q4[5], bs4[2];
cx q4[5], bs4[3];
cx q4[6], bs4[4];
cx q4[7], bs4[5];
cx q4[8], bs4[4];
cx q4[8], bs4[5];
barrier q4[0], q4[1], q4[2], q4[3], q4[4], q4[5], q4[6], q4[7], q4[8], bs4[0], bs4[1], bs4[2], bs4[3], bs4[4], bs4[5], ps4[0], ps4[1];
h ps4[0];
cx ps4[0], q4[0];
cx ps4[0], q4[1];
cx ps4[0], q4[2];
cx ps4[0], q4[6];
cx ps4[0], q4[7];
cx ps4[0], q4[8];
h ps4[0];
h ps4[1];
cx ps4[1], q4[3];
cx ps4[1], q4[4];
cx ps4[1], q4[5];
cx ps4[1], q4[6];
cx ps4[1], q4[7];
cx ps4[1], q4[8];
h ps4[1];
barrier q4[0], q4[1], q4[2], q4[3], q4[4], q4[5], q4[6], q4[7], q4[8], bs4[0], bs4[1], bs4[2], bs4[3], bs4[4], bs4[5], ps4[0], ps4[1];
bsm0[0] = measure bs0[0];
bsm0[1] = measure bs0[1];
bsm0[2] = measure bs0[2];
bsm0[3] = measure bs0[3];
bsm0[4] = measure bs0[4];
bsm0[5] = measure bs0[5];
if (bsm0 == 1) {
  x q0[0];
}
if (bsm0 == 2) {
  x q0[1];
}
if (bsm0 == 3) {
  x q0[2];
}
if (bsm0 == 4) {
  x q0[3];
}
if (bsm0 == 8) {
  x q0[4];
}
if (bsm0 == 12) {
  x q0[5];
}
if (bsm0 == 16) {
  x q0[6];
}
if (bsm0 == 32) {
  x q0[7];
}
if (bsm0 == 48) {
  x q0[8];
}
barrier q0[0], q0[1], q0[2], q0[3], q0[4], q0[5], q0[6], q0[7], q0[8], bs0[0], bs0[1], bs0[2], bs0[3], bs0[4], bs0[5], ps0[0], ps0[1];
psm0[0] = measure ps0[0];
psm0[1] = measure ps0[1];
if (psm0 == 1) {
  z q0[0];
}
if (psm0 == 2) {
  z q0[3];
}
if (psm0 == 3) {
  z q0[6];
}
barrier q0[0], q0[1], q0[2], q0[3], q0[4], q0[5], q0[6], q0[7], q0[8], bs0[0], bs0[1], bs0[2], bs0[3], bs0[4], bs0[5], ps0[0], ps0[1];
cx q0[0], q0[1];
cx q0[0], q0[2];
h q0[0];
cx q0[3], q0[4];
cx q0[3], q0[5];
h q0[3];
cx q0[0], q0[3];
cx q0[6], q0[7];
cx q0[6], q0[8];
h q0[6];
cx q0[0], q0[6];
m0[0] = measure q0[0];
bsm1[0] = measure bs1[0];
bsm1[1] = measure bs1[1];
bsm1[2] = measure bs1[2];
bsm1[3] = measure bs1[3];
bsm1[4] = measure bs1[4];
bsm1[5] = measure bs1[5];
if (bsm1 == 1) {
  x q1[0];
}
if (bsm1 == 2) {
  x q1[1];
}
if (bsm1 == 3) {
  x q1[2];
}
if (bsm1 == 4) {
  x q1[3];
}
if (bsm1 == 8) {
  x q1[4];
}
if (bsm1 == 12) {
  x q1[5];
}
if (bsm1 == 16) {
  x q1[6];
}
if (bsm1 == 32) {
  x q1[7];
}
if (bsm1 == 48) {
  x q1[8];
}
barrier q1[0], q1[1], q1[2], q1[3], q1[4], q1[5], q1[6], q1[7], q1[8], bs1[0], bs1[1], bs1[2], bs1[3], bs1[4], bs1[5], ps1[0], ps1[1];
psm1[0] = measure ps1[0];
psm1[1] = measure ps1[1];
if (psm1 == 1) {
  z q1[0];
}
if (psm1 == 2) {
  z q1[3];
}
if (psm1 == 3) {
  z q1[6];
}
barrier q1[0], q1[1], q1[2], q1[3], q1[4], q1[5], q1[6], q1[7], q1[8], bs1[0], bs1[1], bs1[2], bs1[3], bs1[4], bs1[5], ps1[0], ps1[1];
cx q1[0], q1[1];
cx q1[0], q1[2];
h q1[0];
cx q1[3], q1[4];
cx q1[3], q1[5];
h q1[3];
cx q1[0], q1[3];
cx q1[6], q1[7];
cx q1[6], q1[8];
h q1[6];
cx q1[0], q1[6];
m1[0] = measure q1[0];
bsm2[0] = measure bs2[0];
bsm2[1] = measure bs2[1];
bsm2[2] = measure bs2[2];
bsm2[3] = measure bs2[3];
bsm2[4] = measure bs2[4];
bsm2[5] = measure bs2[5];
if (bsm2 == 1) {
  x q2[0];
}
if (bsm2 == 2) {
  x q2[1];
}
if (bsm2 == 3) {
  x q2[2];
}
if (bsm2 == 4) {
  x q2[3];
}
if (bsm2 == 8) {
  x q2[4];
}
if (bsm2 == 12) {
  x q2[5];
}
if (bsm2 == 16) {
  x q2[6];
}
if (bsm2 == 32) {
  x q2[7];
}
if (bsm2 == 48) {
  x q2[8];
}
barrier q2[0], q2[1], q2[2], q2[3], q2[4], q2[5], q2[6], q2[7], q2[8], bs2[0], bs2[1], bs2[2], bs2[3], bs2[4], bs2[5], ps2[0], ps2[1];
psm2[0] = measure ps2[0];
psm2[1] = measure ps2[1];
if (psm2 == 1) {
  z q2[0];
}
if (psm2 == 2) {
  z q2[3];
}
if (psm2 == 3) {
  z q2[6];
}
barrier q2[0], q2[1], q2[2], q2[3], q2[4], q2[5], q2[6], q2[7], q2[8], bs2[0], bs2[1], bs2[2], bs2[3], bs2[4], bs2[5], ps2[0], ps2[1];
cx q2[0], q2[1];
cx q2[0], q2[2];
h q2[0];
cx q2[3], q2[4];
cx q2[3], q2[5];
h q2[3];
cx q2[0], q2[3];
cx q2[6], q2[7];
cx q2[6], q2[8];
h q2[6];
cx q2[0], q2[6];
m2[0] = measure q2[0];
bsm3[0] = measure bs3[0];
bsm3[1] = measure bs3[1];
bsm3[2] = measure bs3[2];
bsm3[3] = measure bs3[3];
bsm3[4] = measure bs3[4];
bsm3[5] = measure bs3[5];
if (bsm3 == 1) {
  x q3[0];
}
if (bsm3 == 2) {
  x q3[1];
}
if (bsm3 == 3) {
  x q3[2];
}
if (bsm3 == 4) {
  x q3[3];
}
if (bsm3 == 8) {
  x q3[4];
}
if (bsm3 == 12) {
  x q3[5];
}
if (bsm3 == 16) {
  x q3[6];
}
if (bsm3 == 32) {
  x q3[7];
}
if (bsm3 == 48) {
  x q3[8];
}
barrier q3[0], q3[1], q3[2], q3[3], q3[4], q3[5], q3[6], q3[7], q3[8], bs3[0], bs3[1], bs3[2], bs3[3], bs3[4], bs3[5], ps3[0], ps3[1];
psm3[0] = measure ps3[0];
psm3[1] = measure ps3[1];
if (psm3 == 1) {
  z q3[0];
}
if (psm3 == 2) {
  z q3[3];
}
if (psm3 == 3) {
  z q3[6];
}
barrier q3[0], q3[1], q3[2], q3[3], q3[4], q3[5], q3[6], q3[7], q3[8], bs3[0], bs3[1], bs3[2], bs3[3], bs3[4], bs3[5], ps3[0], ps3[1];
cx q3[0], q3[1];
cx q3[0], q3[2];
h q3[0];
cx q3[3], q3[4];
cx q3[3], q3[5];
h q3[3];
cx q3[0], q3[3];
cx q3[6], q3[7];
cx q3[6], q3[8];
h q3[6];
cx q3[0], q3[6];
m3[0] = measure q3[0];
bsm4[0] = measure bs4[0];
bsm4[1] = measure bs4[1];
bsm4[2] = measure bs4[2];
bsm4[3] = measure bs4[3];
bsm4[4] = measure bs4[4];
bsm4[5] = measure bs4[5];
if (bsm4 == 1) {
  x q4[0];
}
if (bsm4 == 2) {
  x q4[1];
}
if (bsm4 == 3) {
  x q4[2];
}
if (bsm4 == 4) {
  x q4[3];
}
if (bsm4 == 8) {
  x q4[4];
}
if (bsm4 == 12) {
  x q4[5];
}
if (bsm4 == 16) {
  x q4[6];
}
if (bsm4 == 32) {
  x q4[7];
}
if (bsm4 == 48) {
  x q4[8];
}
barrier q4[0], q4[1], q4[2], q4[3], q4[4], q4[5], q4[6], q4[7], q4[8], bs4[0], bs4[1], bs4[2], bs4[3], bs4[4], bs4[5], ps4[0], ps4[1];
psm4[0] = measure ps4[0];
psm4[1] = measure ps4[1];
if (psm4 == 1) {
  z q4[0];
}
if (psm4 == 2) {
  z q4[3];
}
if (psm4 == 3) {
  z q4[6];
}
barrier q4[0], q4[1], q4[2], q4[3], q4[4], q4[5], q4[6], q4[7], q4[8], bs4[0], bs4[1], bs4[2], bs4[3], bs4[4], bs4[5], ps4[0], ps4[1];
cx q4[0], q4[1];
cx q4[0], q4[2];
h q4[0];
cx q4[3], q4[4];
cx q4[3], q4[5];
h q4[3];
cx q4[0], q4[3];
cx q4[6], q4[7];
cx q4[6], q4[8];
h q4[6];
cx q4[0], q4[6];
m4[0] = measure q4[0];
barrier q0[0], q0[1], q0[2], q0[3], q0[4], q0[5], q0[6], q0[7], q0[8], bs0[0], bs0[1], bs0[2], bs0[3], bs0[4], bs0[5], ps0[0], ps0[1], q1[0], q1[1], q1[2], q1[3], q1[4], q1[5], q1[6], q1[7], q1[8], bs1[0], bs1[1], bs1[2], bs1[3], bs1[4], bs1[5], ps1[0], ps1[1], q2[0], q2[1], q2[2], q2[3], q2[4], q2[5], q2[6], q2[7], q2[8], bs2[0], bs2[1], bs2[2], bs2[3], bs2[4], bs2[5], ps2[0], ps2[1], q3[0], q3[1], q3[2], q3[3], q3[4], q3[5], q3[6], q3[7], q3[8], bs3[0], bs3[1], bs3[2], bs3[3], bs3[4], bs3[5], ps3[0], ps3[1], q4[0], q4[1], q4[2], q4[3], q4[4], q4[5], q4[6], q4[7], q4[8], bs4[0], bs4[1], bs4[2], bs4[3], bs4[4], bs4[5], ps4[0], ps4[1];
