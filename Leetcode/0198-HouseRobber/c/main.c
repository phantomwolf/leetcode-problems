#include <stdio.h>
#include <stdlib.h>

/* Define d[i] to be the maximum amount 
 * of money robbed from nums[0] to nums[i-1]
 */
int rob(int* nums, int numsSize)
{
    int res;
    int *d = (int *)malloc(sizeof(int) * (numsSize + 1));
    d[0] = 0;
    d[1] = nums[0];
    for (int i = 2; i <= numsSize; ++i) {
        int slt1 = d[i - 1];
        int slt2 = d[i - 2] + nums[i - 1];
        d[i] = (slt1 > slt2) ? slt1 : slt2;
    }
    res = d[numsSize];
    free(d);
    return res;
}


int main()
{
    int nums[4] = {3, 7, 5, 2};
    int money = rob(nums, 4);
    printf("money: %d\n", money);

    return 0;
}
