#include <stdio.h>

#define MAX(a, b)   ((a) > (b) ? (a) : (b))

int maxSubArray(int* nums, int numsSize){
    int curr = nums[0];
    int max = nums[0];
    for (int i=1; i < numsSize; i++) {
        curr = MAX(curr + nums[i], nums[i]);
        max = MAX(curr, max);
    }
    return max;
}

int main(int argc, char *argv[]) {
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int numsSize = 9;
    int res = maxSubArray(nums, numsSize);
    printf("%d\n", res);
    return 0;
}
