#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


// lens[]: 每个单词的长度
// n: lens的长度
// M: 每行最大长度，任何一个单词的长度都小于M
int solveWordWrap(int lens[], int n, int M)
{
    // 累积和
    int sum[n + 1];
    // lc[i][j]: cost of line which has words from i to j
    int lc[n][n];
    // c[i]: total cost of optimal arrangement of words
    int c[n + 1];

    sum[0] = 0;
    for (int i = 0; i < n; ++i) {
        sum[i + 1] = sum[i] + lens[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            // 若将单词i到j放入同一行，该行的长度
            int len = sum[j + 1] - sum[i] + (j - i);
            if (len > M) {
                while (j < n) {
                    lc[i][j++] = INT_MAX;
                }
                break;
            }
            // 最后一行，不用补齐空格
            if (j == n-1 && len <= M) {
                lc[i][j] = 0;
                break;
            }
            lc[i][j] = (M - len) * (M - len);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            printf("lc[%d][%d]: %d\n", i, j, lc[i][j]);
        }
    }

    c[0] = 0;
    for (int j = 0; j <= n; ++j) {
        int min = INT_MAX;
        for (int i = 0; i <= j; ++i) {
            if (lc[i][j] != INT_MAX && c[i] + lc[i][j] < min)
                min = c[i] + lc[i][j];
        }
        c[j + 1] = min;
        printf("c[%d]: %d\n", j, c[j]);
    }

    return 0;
}


int main(int argc, char *argv[])
{
    int M = 6;
    int lens[] = {3, 2, 2, 5};
    int res = solveWordWrap(lens, sizeof(lens) / sizeof(int), M);

    return 0;
}
