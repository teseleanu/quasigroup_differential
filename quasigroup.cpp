#include "quasigroup.h"

void set_xor_quasi_times(unsigned char perm[3][8], unsigned char quasi_op[3][8][8])
{
    for(int x = 0; x < 8; x++)
        for(int y = 0; y < 8; y++)
        {
            unsigned char z = perm[0][perm[1][x] ^ perm[2][y]];
            quasi_op[0][x][y] = z;//times
            quasi_op[1][x][z] = y;//left div
            quasi_op[2][z][y] = x;//right div
        }
}

void set_add_quasi_times(unsigned char perm[3][8], unsigned char quasi_op[3][8][8])
{
    for(int x = 0; x < 8; x++)
        for(int y = 0; y < 8; y++)
        {
            unsigned char z = perm[0][mod_8(perm[1][x] + perm[2][y])];
            quasi_op[0][x][y] = z;//times
            quasi_op[1][x][z] = y;//left div
            quasi_op[2][z][y] = x;//right div
        }
}

void set_minus_quasi_times(unsigned char perm[3][8], unsigned char quasi_op[3][8][8])
{
    for(int x = 0; x < 8; x++)
        for(int y = 0; y < 8; y++)
        {
            unsigned char z = perm[0][mod_8(perm[1][x] - perm[2][y])];
            quasi_op[0][x][y] = z;//times
            quasi_op[1][x][z] = y;//left div
            quasi_op[2][z][y] = x;//right div
        }
}

void set_random_quasi_times(mt19937 &gen, unsigned char quasi_op_in[3][8][8], unsigned char quasi_op_out[3][8][8])
{
    unsigned char perm[3][8];

    set_s_box_table(perm[0], gen);
    set_s_box_table(perm[1], gen);
    set_s_box_table(perm[2], gen);

    for(int x = 0; x < 8; x++)
        for(int y = 0; y < 8; y++)
        {
            unsigned char temp = quasi_op_in[0][perm[1][x]][perm[2][y]];
            unsigned char z = perm[0][temp];
            quasi_op_out[0][x][y] = z;//times
            quasi_op_out[1][x][z] = y;//left div
            quasi_op_out[2][z][y] = x;//right div
        }
}


