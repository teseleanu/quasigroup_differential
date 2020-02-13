#ifndef DIFFERENTIALS_H_INCLUDED
#define DIFFERENTIALS_H_INCLUDED

#include "auxiliary.h"
#include "quasigroup.h"

static const int left_div = 1, right_div = 2;

void set_xor_diff_table(unsigned char s_box_table[8], int diff_table[8][8]);
void set_addition_diff_table(unsigned char s_box_table[8], int diff_table[8][8]);

void set_left_quasigroup_diff_table(unsigned char s_box_table[8], unsigned char op[3][8][8], int diff_table[8][8]);
void set_right_quasigroup_diff_table(unsigned char s_box_table[8], unsigned char op[3][8][8], int diff_table[8][8]);

void set_left_quasigroup_keyed_diff_table(unsigned char s_box_table[8], unsigned char op[3][8][8], unsigned char key, int diff_table[8][8]);
void set_right_quasigroup_keyed_diff_table(unsigned char s_box_table[8], unsigned char op[3][8][8], unsigned char key, int diff_table[8][8]);

int maximum_differential(int diff_table[8][8]);
int maximum_differential_quasi(int diff_table[8][8]);

#endif // DIFFERENTIALS_H_INCLUDED
