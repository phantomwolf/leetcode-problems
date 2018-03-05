#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "integer_hash.h"

int division_hash(int k, size_t m)
{
    return k % m;
}

int kunth_division_hash(int k, size_t m)
{
    return (k * (k + 3)) % m;
}


int multiplication_hash(int k, size_t m)
{
    static double A = (sqrt(5) - 1) * 0.5;
    double s        = k * A;
    return (int)(m * (s - (int)s));
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s num1 [num2 ...]\n", argv[0]);
        exit(255);
    }

    printf("hash functions: division, kunth_division, multiplication\n");

    int *k = (int *)malloc(sizeof(int) * (argc - 1));
    for (int i = 0; i < argc-1; ++i) {
        k[i] = atoi(argv[i+1]);
        printf("%-6d: %-10d %-10d %-10d\n",
               k[i],
               division_hash(k[i], 701),
               kunth_division_hash(k[i], 701),
               multiplication_hash(k[i], 1024));
    }
    return 0;
}
