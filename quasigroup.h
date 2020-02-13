#ifndef QUASIGROUP_H_INCLUDED
#define QUASIGROUP_H_INCLUDED

#include <random>

#include "auxiliary.h"

using namespace std;

void set_xor_quasi_times(unsigned char perm[3][8], unsigned char quasi_op[3][8][8]);
void set_add_quasi_times(unsigned char perm[3][8], unsigned char quasi_op[3][8][8]);
void set_minus_quasi_times(unsigned char perm[3][8], unsigned char quasi_op[3][8][8]);
void set_random_quasi_times(mt19937 &gen, unsigned char quasi_op_in[3][8][8], unsigned char quasi_op_out[3][8][8]);

#endif // QUASIGROUP_H_INCLUDED
