#include <stdio.h>
#include <stdlib.h>

int singleNonDuplicate(int *nums, int numsSize)
{
    int i = 0, j = numsSize - 1;
    while (i != j) {
        int mid = i + (j - i + 2) / 4 * 2;
        if (nums[mid] == nums[mid - 1]) {
            j = mid - 2;
        } else if (nums[mid] == nums[mid + 1]) {
            i = mid + 2;
        } else {
            return nums[mid];
        }
    }
    return nums[i];
}

int *testcase_generator(int numsSize, int missing)
{
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    int generator = 1;
    int i = 0;
    while (i != numsSize) {
        if (generator == missing) {
            nums[i++] = generator++;
            continue;
        }
        nums[i++] = generator;
        nums[i++] = generator++;
    }
    return nums;
}


int main(int argc, char *argv[])
{
    int numsSize = 1025;
    int *nums = testcase_generator(numsSize, 135);
    /*printf("[");
    for (int i = 0; i < numsSize; ++i) {
        printf("%d,", nums[i]);
    }
    puts("]");*/

    int res = singleNonDuplicate(nums, numsSize);
    free(nums);
    printf("Result: %d\n", res);

    return 0;
}
