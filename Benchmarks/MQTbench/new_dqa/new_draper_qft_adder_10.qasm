OPENQASM 2.0;
include "qelib1.inc";
gate circuit_42 q0,q1,q2,q3,q4 { h q4; cp(pi/2) q4,q3; cp(pi/4) q4,q2; cp(pi/8) q4,q1; cp(pi/16) q4,q0; h q3; cp(pi/2) q3,q2; cp(pi/4) q3,q1; cp(pi/8) q3,q0; h q2; cp(pi/2) q2,q1; cp(pi/4) q2,q0; h q1; cp(pi/2) q1,q0; h q0; }
gate circuit_42_dg q0,q1,q2,q3,q4 { h q0; cp(-pi/2) q1,q0; h q1; cp(-pi/4) q2,q0; cp(-pi/2) q2,q1; h q2; cp(-pi/8) q3,q0; cp(-pi/4) q3,q1; cp(-pi/2) q3,q2; h q3; cp(-pi/16) q4,q0; cp(-pi/8) q4,q1; cp(-pi/4) q4,q2; cp(-pi/2) q4,q3; h q4; }
qreg a[5];
qreg b[5];
creg meas[10];
circuit_42 b[0],b[1],b[2],b[3],b[4];
cp(pi) a[0],b[0];
cp(pi/2) a[0],b[1];
cp(pi/4) a[0],b[2];
cp(pi/8) a[0],b[3];
cp(pi/16) a[0],b[4];
cp(pi) a[1],b[1];
cp(pi/2) a[1],b[2];
cp(pi/4) a[1],b[3];
cp(pi/8) a[1],b[4];
cp(pi) a[2],b[2];
cp(pi/2) a[2],b[3];
cp(pi/4) a[2],b[4];
cp(pi) a[3],b[3];
cp(pi/2) a[3],b[4];
cp(pi) a[4],b[4];
circuit_42_dg b[0],b[1],b[2],b[3],b[4];
