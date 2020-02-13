#include "auxiliary.h"

int mod_8(int a)
{
    if(a%8 >= 0) return a%8;
    else return 8+a%8;
}

void set_s_box_table(unsigned char s_box_table[8], mt19937 &gen)
{
    for(int i = 0; i < 8; i++)
        s_box_table[i] = i;

    shuffle(s_box_table, s_box_table+8, gen);
}

double sample_mean(int *x, int size_x)
{
    double sum = 0.0;

    for(int i = 0; i < size_x; i++)
        sum += x[i];

    return sum/size_x;
}

double sample_mean_absolute_deviation(int *x, int size_x, double sample_mean)
{
    double sum = 0.0;

    for(int i = 0; i < size_x; i++)
        sum += abs(x[i]-sample_mean);

    return sum/size_x;
}

void print_table(int diff_table[8][8])
{
    #ifdef LATEX
    cout << endl << "  & ";
    for(int j = 0; j < 8; j++)
        cout << "~$" << j << "$~ & ";
    cout << "\\\\" << endl << "\\hline" << endl;

    for(int j = 0; j < 8; j++)
    {
        cout << "$" << j << "$ & ";
        for(int k = 0; k < 8; k++)
            cout << "$" << (int) diff_table[j][k] << "$ & ";
        cout << "\\\\" << endl << "\\hline" << endl;
    }
    #else
    for(int j = 0; j < 8; j++)
    {
        for(int k = 0; k < 8; k++)
            cout << (int) diff_table[j][k] << " ";
        cout << endl;
    }
    cout << endl;
    #endif
}
