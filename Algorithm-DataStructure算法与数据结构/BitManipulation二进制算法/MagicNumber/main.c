#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


uint32_t magic_number(uint32_t n)
{
    uint32_t res = 0;
    uint32_t power = 5;
    while (n != 0) {
        if (n & 1)
            res += power;
        power *= 5;
        n >>= 1;
    }
    return res;
}

int main(int argc, char *argv[])
{
    uint32_t n = 6;
    uint32_t magic = magic_number(n);
    printf("%uth magic number: %u\n", n, magic);

    return 0;
}
