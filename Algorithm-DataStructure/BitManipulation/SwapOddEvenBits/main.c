#include <stdio.h>
#include <stdint.h>


uint32_t swap_odd_even(uint32_t num)
{
    uint32_t odd_bits  = num & 0x55555555;
    uint32_t even_bits = num & 0xAAAAAAAA;
    return (odd_bits << 1) | (even_bits >> 1);
}


int main(int argc, char *argv[])
{
    uint32_t num = 23;
    uint32_t res = swap_odd_even(num);
    printf("%-5u => %5u\n", num, res);

    return 0;
}
