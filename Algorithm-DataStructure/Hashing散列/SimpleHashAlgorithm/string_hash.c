#include <stdio.h>
#include <stdlib.h>

#include "string_hash.h"

unsigned long djb2(char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        /* hash = hash * 33 + c */
        hash = ((hash << 5) + hash) + c;

    return hash;
}

unsigned long sdbm(char *str)
{
    unsigned long hash = 0;
    int c;

    while (c = *str++)
        /* hash(i) = hash(i - 1) * 65599 + str[i] */
        hash = c + (hash << 6) + (hash << 16) - hash;

    return hash;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s str1 [str2 ...]\n", argv[0]);
        exit(255);
    }

    printf("hash functions: djb2, sdbm\n");

    for (int i = 1; i < argc; ++i) {
        printf("%-20s: %-20lu %-20lu\n",
               argv[i],
               djb2(argv[i]),
               sdbm(argv[i]));
    }

    return 0;
}
