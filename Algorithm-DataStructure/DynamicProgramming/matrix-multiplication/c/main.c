#include <limits.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define MATRIX  {5, 10, 3, 12, 5, 50, 6}
#define SIZE    6   // 6 matrix in total

int calc(int p[SIZE+1], int m[SIZE][SIZE], int s[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; ++i) {
        m[i][i] = 0;
        for (int j = i + 1; j < SIZE; ++j) {
            m[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                // (Ai...Ak) x (Ak+1...Aj)
                int q = m[i][k] + m[k+1][j] + p[i] * p[k+1] * p[j+1];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    return m[0][SIZE-1];
}

void print_matrix(int m[SIZE][SIZE], char *name)
{
    printf("%s:\n", name);
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            printf("%-8d", m[i][j]);
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[])
{
    int p[] = MATRIX;   // A0(p[0], p[1]), A1(p[1], p[2])
    int m[SIZE][SIZE];
    int s[SIZE][SIZE];

    memset(m, 0, sizeof(int) * SIZE * SIZE);
    memset(s, 0, sizeof(int) * SIZE * SIZE);

    char buf[32];
    printf("matrix:\n");
    for (int i = 0; i < SIZE; ++i) {
        snprintf(buf, 32, "%dx%d", p[i], p[i+1]);
        printf("%-9s", buf);
    }
    puts("\n");

    printf("p:\n");
    for (int i = 0; i < SIZE; ++i) {

    calc(p, m, s);

    print_matrix(m, "m");
    print_matrix(s, "s");

    return 0;
}
