#include <stdio.h>
#include <stdlib.h>

#include "integer_hash.h"

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s num1 [num2 ...]\n", argv[0]);
        exit(255);
    }

    printf("hash functions: division, kunth_division, multiplication, multiplication_i\n");

    int *k = (int *)malloc(sizeof(int) * (argc - 1));
    for (int i = 0; i < argc-1; ++i) {
        k[i] = atoi(argv[i+1]);
        printf("%-6d: %-10d %-10d %-10d %-10d\n",
               k[i],
               division_hash(k[i], 701),
               kunth_division_hash(k[i], 701),
               multiplication_hash(k[i], 1024));
    }
    return 0;
}
