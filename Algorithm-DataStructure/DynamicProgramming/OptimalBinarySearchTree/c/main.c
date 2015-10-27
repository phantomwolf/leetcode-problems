#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE    6

// w[i][j] = (p[i] + p[i+1] + ... + p[j-1] + p[j]) + (q[i-1] + q[i] + q[i+1] + ... q[j-1] + q[j])
// e[i][j] = e[i][r-1] + e[r+1][j] + w[i][j]
double solution(double p[SIZE], double q[SIZE],
                double e[SIZE][SIZE], double r[SIZE][SIZE],
                double w[SIZE][SIZE])
{
    for (int i = 1; i < SIZE; ++i) {
        e[i][i-1] = q[i-1];
        w[i][i-1] = q[i-1];
    }
    // 这里的计算顺序，不能简单地用i和j地双重循环，而是需要先计算
    // 长度较小的序列，然后增加长度。因为较长的序列的结果依赖较短序列
    for (int l = 1; l < SIZE; ++l) {
        for (int i = 1; i <= SIZE - l; ++i) {
            int j = i + l - 1;
            w[i][j] = w[i][j-1] + p[j] + q[j];
            e[i][j] = DBL_MAX;
            for (int m = i; m <= j; ++m) {
                double tmp = e[i][m-1] + e[m+1][j] + w[i][j];
                if (tmp < e[i][j]) {
                    e[i][j] = tmp;
                    r[i][j] = m;
                }
            }
        }
    }
    return e[1][SIZE-1];
}

int main(int argc, char *argv[])
{
    //                  0       1       2       3       4       5
    double p[SIZE]  = { 0,      0.15,   0.10,   0.05,   0.10,   0.20};
    double q[SIZE]  = { 0.05,   0.10,   0.05,   0.05,   0.05,   0.10};
    double e[SIZE][SIZE] = {};
    double r[SIZE][SIZE] = {};
    double w[SIZE][SIZE] = {};
    double res;

    res = solution(p, q, e, r, w);
    printf("Result: %f\n", res);
    
    return 0;
}
