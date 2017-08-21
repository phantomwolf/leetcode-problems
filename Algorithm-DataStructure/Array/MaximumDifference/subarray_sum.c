#include <stdio.h>


int maximum_difference1(int nums[], int n)
{
    if (n < 2)
        return -1;

    int diff[n - 1];
    for (int i = 1; i < n; i++) {
        diff[i - 1] = nums[i] - nums[i - 1];
    }
    // subarray sum
    int max_sum = 0;
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum = (sum > 0) ? sum + diff[i] : diff[i];
        if (max_sum < sum)
            max_sum = sum;
    }
    return max_sum;
}

// 实际上不需要diff数组，每个diff[i]只用到一次而已
// 我们用一个diff变量来代替diff数组
int maximum_difference2(int nums[], int n)
{
    if (n < 2)
        return -1;

    int diff = 0;
    int sum = 0;
    int max_sum = 0;
    for (int i = 1; i < n; i++) {
        diff = nums[i] - nums[i - 1];
        printf("diff: %d\n", diff);
        sum = (sum > 0) ? sum + diff : diff;
        if (max_sum < sum)
            max_sum = sum;
    }
    return max_sum;
}

int main(int argc, char *argv[])
{
    int max_diff;
    int nums1[] = {2, 3, 10, 6, 4, 8, 1};
    int nums2[] = {7, 9, 5, 6, 3, 2};
    max_diff = maximum_difference2(nums1, sizeof(nums1) / sizeof(int));
    printf("max_diff1: %d\n", max_diff);

    max_diff = maximum_difference2(nums2, sizeof(nums2) / sizeof(int));
    printf("max_diff2: %d\n", max_diff);

    return 0;
}
