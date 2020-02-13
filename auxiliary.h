#ifndef AUXILIARY_H_INCLUDED
#define AUXILIARY_H_INCLUDED

#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

extern const int iteratii;

//Latex table formating
//#define LATEX

int mod_8(int a);
void set_s_box_table(unsigned char s_box_table[8], mt19937 &gen);
void print_table(int diff_table[8][8]);

#endif // AUXILIARY_H_INCLUDED
