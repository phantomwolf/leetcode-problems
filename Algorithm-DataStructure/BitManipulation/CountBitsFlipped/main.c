#include <stdio.h>
#include <stdint.h>


uint32_t count_bits_flipped(uint32_t a, uint32_t b)
{
    uint32_t count = 0;
    uint32_t diff = a ^ b;
    while (diff > 0) {
        count += diff & 1;
        diff >>= 1;
    }
    return count;
}


int main(int argc, char *argv[])
{
    uint32_t a = 10;
    uint32_t b = 20;

    printf("Bits needed to be flipped: %u\n", count_bits_flipped(a, b));

    return 0;
}
