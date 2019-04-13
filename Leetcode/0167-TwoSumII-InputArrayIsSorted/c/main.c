#include <stdio.h>
#include <stdlib.h>


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    int *res = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    int i = 0, j = numbersSize - 1;
    while (i < j) {
        if (numbers[i] + numbers[j] == target) {
            res[0] = i + 1;
            res[1] = j + 1;
            break;
        } else if (numbers[i] + numbers[j] < target) {
            ++i;
        } else {
            --j;
        }
    }
    return res;
}


int main(int argc, char *argv[])
{
    int numbers[] = {2, 3, 4};
    int target = 6;
    int returnSize;
    int *res = twoSum(numbers, 3, target, &returnSize);

    printf("indexes: %d, %d\n", res[0], res[1]);
    free(res);

    return 0;
}
