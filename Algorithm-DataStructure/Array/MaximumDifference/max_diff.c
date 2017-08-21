#include <stdio.h>
#include <limits.h>


int maximum_difference(int nums[], int n)
{
    if (n < 2)
        return -1;

    int max_diff = INT_MIN;
    int curr_min = nums[0];
    for (int i = 1; i < n; ++i) {
        int curr_diff = nums[i] - curr_min;
        if (max_diff < curr_diff)
            max_diff = curr_diff;
        if (curr_min > nums[i])
            curr_min = nums[i];
    }
    return (max_diff > 0) ? max_diff : -1;
}


int main(int argc, char *argv[])
{
    int max_diff;
    int nums1[] = {2, 3, 10, 6, 4, 8, 1};
    int nums2[] = {7, 9, 5, 6, 3, 2};
    max_diff = maximum_difference(nums1, sizeof(nums1) / sizeof(int));
    printf("max_diff1: %d\n", max_diff);

    max_diff = maximum_difference(nums2, sizeof(nums2) / sizeof(int));
    printf("max_diff2: %d\n", max_diff);

    return 0;
}
