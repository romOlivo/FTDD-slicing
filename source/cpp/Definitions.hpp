#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <random>

#include <string>
#include <cmath>
#include <limits>
#include <complex>

#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <eigen3/Eigen/Dense>

#include <graphviz/gvc.h>

typedef double dataType;
typedef int8_t keyType;
typedef uint16_t refCntType;
typedef Eigen::VectorXcd complexArrayType;
typedef std::uint32_t hashType;

/*
    Global Variables
*/

// 32-bit FNV hash parameters
extern hashType fnv_prime;
extern hashType fnv_offset_basis;

extern dataType epi;
extern dataType epi_inv;

// two-level quantum system
extern uint succ_num;

constexpr double TOLERANCE = 1e-14;

#endif