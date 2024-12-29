#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define X "acbaed"
#define Y "abcadf"
#define XSIZE 6
#define YSIZE 6
#define SIZE 7

int solution(char *x, char *y, int m[XSIZE + 1][YSIZE + 1], char s[XSIZE+1][YSIZE+1])
{
    memset(m, 0, sizeof(int) * (XSIZE+1) * (YSIZE+1));
    memset(s, 0, sizeof(char) * (XSIZE+1) * (YSIZE+1));
    for (int i = 1; i <= XSIZE; ++i) {
        for (int j = 1; j <= YSIZE; ++j) {
            if (x[i-1] == y[j-1]) {
                m[i][j] = m[i-1][j-1] + 1;
                s[i][j] = '&';
            } else if (m[i-1][j] >= m[i][j-1]) {
                m[i][j] = m[i-1][j];
                s[i][j] = 'l';
            } else {
                m[i][j] = m[i][j-1];
                s[i][j] = 'r';
            }
        }
    }
    return m[XSIZE][YSIZE];
}

void printLCSRecursive(char s[XSIZE+1][YSIZE+1], char *x, char *y, int m, int n)
{
    int i = m, j = n;
    if (i >= 0 && j >= 0) {
        if (s[i][j] == '&') {
            printLCSRecursive(s, x, y, m-1, n-1);
            printf("%c", x[i-1]);
        } else if (s[i][j] == 'l') {
            printLCSRecursive(s, x, y, m-1, n);
        } else if (s[i][j] == 'r') {
            printLCSRecursive(s, x, y, m, n-1);
        }
    }
}

int main(int argc, char *argv[])
{
    char *x = X;
    char *y = Y;
    // correct LCS: acad, length: 4
    int m[XSIZE+1][YSIZE+1];
    char s[XSIZE+1][YSIZE+1];

    int length = solution(x, y, m, s);
    printf("LCS length: %d\n", length);
    printLCSRecursive(s, x, y, XSIZE, YSIZE);
    putchar('\n');
    return 0;
}
