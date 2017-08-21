#include <stdio.h>


int brian_kernighan(unsigned int x)
{
    int count = 0;
    while (x) {
        x &= x - 1;
        count++;
    }
    return count;
}


int main(int argc, char *argv[])
{
    int nums[] = {6, 13};
    for (int i = 0; i < sizeof(nums) / sizeof(int); ++i) {
        int count = __builtin_popcount(nums[i]);
        printf("%d has %d set bits. my result: %d\n", nums[i], count, brian_kernighan(nums[i]));
    }

    return 0;
}
