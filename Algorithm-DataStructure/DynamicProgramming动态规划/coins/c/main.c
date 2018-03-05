#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define COINS_SIZE  4

unsigned int min(unsigned int buf[], size_t size)
{
    unsigned int ret = buf[0];
    for (int i=1; i < size; ++i) {
        if (buf[i] < ret)
            ret = buf[i];
    }
    return ret;
}

unsigned int how_many_coins_do_we_need(unsigned int coins[],
                        size_t size, unsigned int target)
{
    unsigned int *buf;
    unsigned int *d;
    buf = (unsigned int *)malloc(sizeof(unsigned int) * size);
    d = (unsigned int *)malloc(sizeof(unsigned int) * (target + 1));
    d[0] = 0;
    for (int i=1; i <= target; ++i) {
        d[i] = UINT_MAX;
    }
    for (int i=1; i <= target; ++i) {
        for (int j=0; j < size; ++j) {
            if (coins[j] > target)
                buf[j] = UINT_MAX;
            else {
                int tmp = 
                buf[j] = d[target - coins[j]] + 1;
            }
        }
    }
    free(d);
    free(buf);
}

int main(int argc, char *argv[])
{
    int coins[COINS_SIZE] = {1, 3, 5, 7};

    int ret;
    ret = how_many_coins_do_we_need(coins);
    printf("We need %d coins\n", ret);
    return 0;
}
