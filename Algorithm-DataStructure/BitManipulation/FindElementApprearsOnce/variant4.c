#include <stdio.h>
#include <stdint.h>

uint32_t find_missing(uint32_t nums[], size_t n)
{
    // 出现第1次、第4次、第7次的bit
    uint32_t ones = 0;
    // 出现第2次、第5次、第8次的bit
    uint32_t twos = 0;
    // ones与twos共有的bit取反
    uint32_t common_bit_mask;

    for (int i = 0; i < n; ++i) {
        // 将ones与新元素共有的bit(即出现两次的bit)，添加到twos上。
        // 现在twos包含上一轮twos里的所有bit，加上新的bit们。
        // 两者可能会有重复的地方，这些地方其实就是出现了3次的bit。 
        // 所以现在twos同时包含出现2次和3次的bit
        twos |= ones & nums[i];

        // 用XOR操作，只保留出现奇数次的bit(包括1次和3次)
        ones ^= nums[i];

        // 找出ones和twos共有的bit，并取反
        // ones与twos共有的bit，即出现三次的bit
        common_bit_mask = ~(ones & twos);

        printf("ones: %#x, twos: %#x, common: %#x\n", ones, twos, common_bit_mask);

        // 将出现3次的bit从ones和twos中去掉
        ones &= common_bit_mask;
        twos &= common_bit_mask;
    }
    return ones;
}

int main(int argc, char *argv[])
{
    uint32_t nums[] = {1, 3, 5, 11};
    uint32_t res = find_missing(nums, sizeof(nums) / sizeof(uint32_t));
    printf("result: %u\n", res);

    return 0;
}
