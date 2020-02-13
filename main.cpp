#include <iostream>
#include <random>
#include <array>
#include <algorithm>

#include "differentials.h"

using namespace std;

const int iteratii = 1;//000;

void compute_max_diff(mt19937 &gen)
{
    unsigned char s_box_table[8];
    unsigned char perm[3][8], op_q[3][8][8];
    int diff_table[8][8] = {0};
    int key = 0;

    for(int i = 0; i < iteratii; i++)
    {
        set_s_box_table(s_box_table, gen);

        set_s_box_table(perm[0], gen);
        set_s_box_table(perm[1], gen);
        set_s_box_table(perm[2], gen);
        set_s_box_table(perm[1], gen);

        set_xor_diff_table(s_box_table, diff_table);
        cout << "XOR" << endl << "Max diff: " << maximum_differential(diff_table) << endl;
        print_table(diff_table);

        set_xor_quasi_times(perm, op_q);

        set_left_quasigroup_diff_table(s_box_table, op_q, diff_table);
        cout << "Left quasi" << endl << "Max diff: " <<  maximum_differential_quasi(diff_table) << endl;
        print_table(diff_table);

        set_left_quasigroup_keyed_diff_table(s_box_table, op_q, key, diff_table);
        cout << "Left key quasi" << endl << "Max diff: " <<  maximum_differential_quasi(diff_table) << endl;
        print_table(diff_table);

        set_right_quasigroup_diff_table(s_box_table, op_q, diff_table);
        cout << "Right quasi" << endl << "Max diff: " <<  maximum_differential_quasi(diff_table) << endl;
        print_table(diff_table);

        set_right_quasigroup_keyed_diff_table(s_box_table, op_q, key, diff_table);
        cout << "Right key quasi" << endl << "Max diff: " <<  maximum_differential_quasi(diff_table) << endl;
        print_table(diff_table);
    }
}

int main()
{
    mt19937 gen;
    compute_max_diff(gen);

    return 0;
}
