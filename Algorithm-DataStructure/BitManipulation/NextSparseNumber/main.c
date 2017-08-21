#include <stdio.h>
#include <stdint.h>


int32_t next_sparse_num(int32_t x)
{
    uint32_t get_mask = 7;                // 0000 0111，用于获取3个连续的bit。
    uint32_t expected = 3;                // 0000 0011，用于识别获取的3个bit模式是否为011
    uint32_t set_mask = 0xFFFFFFFF << 2;  // 1111 1100，用于快速将连续的1后面的位设为0
    while (get_mask != 0xE0000000) {
        if ((x & get_mask) == expected) {
            x |= get_mask;
            x &= set_mask;
        }
        get_mask <<= 1;
        expected <<= 1;
        set_mask <<= 1;
    }
    return x;
}


int main(int argc, char *argv[])
{
    int32_t x, res;

    x = 6;
    res = next_sparse_num(x);
    printf("next sparse number: %d\n", res);

    x = 38;
    res = next_sparse_num(x);
    printf("next sparse number: %d\n", res);

    x = 44;
    res = next_sparse_num(x);
    printf("next sparse number: %d\n", res);

    return 0;
}
