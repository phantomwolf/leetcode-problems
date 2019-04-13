#include <stdio.h>
#include <float.h>
#include <stdlib.h>


double findMaxAverage(int *nums, int numsSize, int k)
{
    double sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += nums[i];
    }

    double max = sum / k;
    for (int i = k; i < numsSize; ++i) {
        sum = sum - nums[i - k] + nums[i];
        double tmp = sum / k;
        if (tmp > max) {
            max = tmp;
        }
    }
    return max;
}

int main(int argc, char *argv[])
{
    int nums[] = {1, 12, -5, -6, 50, 3};
    int k = 4;
    double result = findMaxAverage(nums, sizeof(nums) / sizeof(int), k);
    printf("result: %lf\n", result);
    return 0;
}
