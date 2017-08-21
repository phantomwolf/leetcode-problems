#include <stdio.h>
#include <stdint.h>


// left rotate n by d bits
uint8_t left_rotate(uint8_t n, uint8_t d)
{
    d %= sizeof(n) * 8;
    return (n << d) | (n >> (sizeof(n) * 8 - d));
}

// right rotate n by d bits
uint8_t right_rotate(uint8_t n, uint8_t d)
{
    d %= sizeof(n) * 8;
    return (n >> d) | (n << (sizeof(n) * 8 - d));
}


int main(int argc, char *argv[])
{
    int n = 128;
    int d = 2;

    uint8_t left = left_rotate(n, d);
    uint8_t right = right_rotate(n, d);

    printf("n: %u\nleft rotate %d bits: %u\nright rotate %d bits: %u\n", n, d, left, d, right);

    return 0;
}
