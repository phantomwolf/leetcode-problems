#include <limits.h>
#include <stdio.h>

int largest_value_of_formula(int *nums, int nums_size)
{
    int max1 = INT_MIN, max2 = INT_MIN;
    for (int i = 0; i < nums_size; ++i) {
        if (max1 < nums[i] - i)
            max1 = nums[i] - i;
        if (max2 < nums[i] + i)
            max2 = nums[i] + i;
    }
    printf("max(nums[i] - i): %d, max(nums[j] + j): %d\n", max1, max2);
    return max1 + max2;
}


int main(int argc, char *argv[])
{
    int nums[] = {4, 6, 8, 2, 1, 6, 1};
    int nums_size = 7;
    int res = largest_value_of_formula(nums, nums_size);
    printf("res: %d\n", res);

    return 0;
}
