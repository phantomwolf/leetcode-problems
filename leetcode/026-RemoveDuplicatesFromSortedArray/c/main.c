#include <stdio.h>


int removeDuplicates(int* nums, int numsSize)
{
    if (numsSize == 0)
        return 0;
    int j = 1;
    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] != nums[i-1]) {
            if (i != j)
                nums[j] = nums[i];
            ++j;
        }
    }
    return j;
}


int main()
{
    int nums[10] = {1, 1, 2, 3, 3, 5, 5, 5, 8, 8};
    int size = removeDuplicates(nums, 10);
    for (int i = 0; i < size; ++i) {
        printf("%d, ", nums[i]);
    }
    putchar('\n');
}
