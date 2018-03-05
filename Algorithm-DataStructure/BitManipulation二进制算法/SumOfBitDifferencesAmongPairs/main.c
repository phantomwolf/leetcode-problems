#include <stdio.h>
#include <stdint.h>


int sum_bit_diff(uint32_t nums[], size_t n)
{
    if (n <= 0)
        return -1;

    int count = 0;
    uint32_t probe = 0x80000000;
    while (probe != 0) {
        int one_count = 0;      // How many 1 are there at this bit
        for (size_t i = 0; i < n; ++i) {
            if (probe & nums[i])
                ++one_count;
        }
        // the amount of 0 at this bit is: n - one_count
        count += one_count * (n - one_count);
        probe >>= 1;
    }
    count <<= 1;    // count *= 2
    return count;
}


int main(int argc, char *argv[])
{
    uint32_t nums1[] = {1, 2};
    uint32_t nums2[] = {1, 3, 5};

    int count1 = sum_bit_diff(nums1, sizeof(nums1) / sizeof(uint32_t));
    int count2 = sum_bit_diff(nums2, sizeof(nums2) / sizeof(uint32_t));

    printf("%d: [", count1);
    for (size_t i = 0; i < sizeof(nums1) / sizeof(uint32_t); ++i) {
        printf("%d, ", nums1[i]);
    }
    printf("]\n%d: [", count2);
    for (size_t i = 0; i < sizeof(nums2) / sizeof(uint32_t); ++i) {
        printf("%d, ", nums2[i]);
    }
    printf("]\n");
    
    return 0;
}
