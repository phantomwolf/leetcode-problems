#include <stdio.h>
#include <stdint.h>


uint32_t count_bits(uint32_t n)
{
    uint32_t count = 0;
    uint32_t probe = 1 << 31;
    int      pos   = 31;
    while (pos > 0) {
        // find next leftmost bit set to 1
        while (pos > 0 && (probe & n) == 0) {
            probe >>= 1;
            --pos;
        }
        if (pos == 0)
            break;
        // set bit to 0
        n ^= probe;
        // top-right：  (2^pos) * pos / 2
        // bottom-left：n+1
        count += n + 1;
        count += (1 << pos - 1) * pos;

        probe >>= 1;
        --pos;
    }
    count += n;
    return count;
}


int main(int argc, char *argv[])
{
    uint32_t count = count_bits(17);
    printf("count: %u\n", count);

    return 0;
}
