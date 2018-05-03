#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#define MAX(a, b)       (((a) > (b)) ? (a) : (b))

// k levels in total. n eggs.
int egg_drop(int n, int k)
{
    // d[i][j]: How many trials we need to find the critical floor given i eggs and j floors in total
    int d[n + 1][k + 1];

    // 1 trial for one floor and 0 trial for 0 floor
    for (int i = 1; i <= n; ++i) {
        d[i][1] = 1;
        d[i][0] = 0;
    }

    // j trials for 1 egg and j floors
    for (int j = 1; j <= k; ++j) {
        d[1][j] = j;
        d[0][j] = INT_MAX;
    }
    
    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= k; ++j) {
            d[i][j] = INT_MAX;
            for (int x = 1; x <= j; ++x) {
                int tmp = 1 + MAX(d[i - 1][x - 1], d[i][j - x]);
                if (tmp < d[i][j])
                    d[i][j] = tmp;
            }
            printf("d[%d][%d]: %d\n", i, j, d[i][j]);
        }
    }
    return d[n][k];
}


int main(int argc, char *argv[])
{
    int n = 2, k = 36;

    int res = egg_drop(n, k);
    printf("result: %d\n", res);

    return 0;
}
