#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * length:  1   2   3   4   5   6   7   8   9   10
 * price:   1   5   8   9   10  17  17  20  24  30
 */
size_t PRICES[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

void usage(char *name)
{
    printf("Usage: %s total_length\n", name);
}

/* Return the max price */
size_t solution(size_t total_length,
                size_t **r,
                size_t **s)
{
    *r = (size_t *)malloc(sizeof(size_t) * (total_length + 1));
    (*r)[0] = 0;
    *s = (size_t *)malloc(sizeof(size_t) * (total_length + 1));
    (*s)[0] = 0;
    for (size_t i = 1; i <= total_length; ++i) {
        (*r)[i] = 0;
        for (size_t j = 1; j <= 10 && j <= i; ++j) {
            int price = (*r)[i - j] + PRICES[j];
            if (price > (*r)[i]) {
                (*r)[i] = price;
                (*s)[i] = j;
            }
        }
    }
    return (*r)[total_length];
}


int main(int argc, char *argv[])
{
    size_t total_length;
    if (argc != 2) {
        usage(argv[0]);
        exit(255);
    }
    total_length = atoi(argv[1]);
    if (total_length == 0) {
        puts("total_length must be a positive integer");
        usage(argv[0]);
        exit(255);
    }
    printf("total length: %lu\n", total_length);

    size_t *r;
    size_t *s;
    solution(total_length, &r, &s);

    printf("\nr: ");
    for (int i = 0; i <= total_length; ++i) {
        printf("%3lu", r[i]);
    }
    printf("\ns: ");
    for (int i = 0; i <= total_length; ++i) {
        printf("%3lu", s[i]);
    }

    // print all the choices made
    printf("\nchoices: ");
    while (total_length > 0) {
        printf("%4lu", s[total_length]);
        total_length -= s[total_length];
    }
    printf("\n");
    return 0;
}
