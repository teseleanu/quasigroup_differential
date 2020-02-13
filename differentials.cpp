#include "differentials.h"

void set_xor_diff_table(unsigned char s_box_table[8], int diff_table[8][8])
{
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            diff_table[i][j] = 0;

    for(int alpha = 0; alpha < 8; alpha++)
        for(int x = 0; x < 8; x++)
        {
            int beta = s_box_table[x]^s_box_table[x^alpha];
            diff_table[alpha][beta]++;
        }
}

void set_addition_diff_table(unsigned char s_box_table[8], int diff_table[8][8])
{
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            diff_table[i][j] = 0;

    for(int alpha = 0; alpha < 8; alpha++)
        for(int x = 0; x < 8; x++)
        {
            int beta = mod_8(s_box_table[mod_8(x+alpha)] - s_box_table[x]);
            diff_table[alpha][beta]++;
        }
}

void set_quasigroup_diff_table(unsigned char s_box_table[8], unsigned char op[3][8][8], int diff_table[8][8], int flag)
{
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            diff_table[i][j] = 0;

    for(int x = 0; x < 8; x++)
        for(int y = 0; y < 8; y++)
        {
            int alpha = op[flag][x][y];
            int beta = op[flag][s_box_table[x]][s_box_table[y]];

            diff_table[alpha][beta]++;
        }
}

void set_left_quasigroup_diff_table(unsigned char s_box_table[8], unsigned char op[3][8][8], int diff_table[8][8])
{
    set_quasigroup_diff_table(s_box_table, op, diff_table, left_div);
}

void set_right_quasigroup_diff_table(unsigned char s_box_table[8], unsigned char op[3][8][8], int diff_table[8][8])
{
    set_quasigroup_diff_table(s_box_table, op, diff_table, right_div);
}

void set_quasigroup_keyed_diff_table(unsigned char s_box_table[8], unsigned char op[3][8][8], unsigned char key, int diff_table[8][8], int flag)
{
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            diff_table[i][j] = 0;

    for(int x = 0; x < 8; x++)
        for(int y = 0; y < 8; y++)
        {
            int alpha = op[flag][x][y];
            int k_x, k_y;

            if(flag == left_div)
            {
                k_x = op[0][key][x];
                k_y = op[0][key][y];
            }
            else
            {
                k_x = op[0][x][key];
                k_y = op[0][y][key];
            }

            int beta = op[flag][s_box_table[k_x]][s_box_table[k_y]];

            diff_table[alpha][beta]++;
        }
}

void set_left_quasigroup_keyed_diff_table(unsigned char s_box_table[8], unsigned char op[3][8][8], unsigned char key, int diff_table[8][8])
{
    set_quasigroup_keyed_diff_table(s_box_table, op, key, diff_table, left_div);
}

void set_right_quasigroup_keyed_diff_table(unsigned char s_box_table[8], unsigned char op[3][8][8], unsigned char key, int diff_table[8][8])
{
    set_quasigroup_keyed_diff_table(s_box_table, op, key, diff_table, right_div);
}

int maximum_differential(int diff_table[8][8])
{
    int diff_max = 0;

    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            if(i!= 0 && j!= 0) diff_max = max(diff_max, diff_table[i][j]);

    return diff_max;
}

int maximum_differential_quasi(int diff_table[8][8])
{
    int diff_max = 0;

    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            diff_max = max(diff_max, diff_table[i][j]);

    return diff_max;
}

