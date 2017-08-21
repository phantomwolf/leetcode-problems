#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    if (*(int*)a > *(int*)b)
        return 1;
    else if (*(int*)a < *(int*)b)
        return -1;
    else
        return 0;
}

// Count triplets with sum smaller than sum
int count_triplets_smaller_than_sum(int nums[], size_t n, int sum)
{
    int res = 0;

    // sort array
    qsort(nums, n, sizeof(int), cmp);

    for (size_t i = 0; i < n - 2; ++i) {
        size_t l = i + 1, r = n - 1;
        while (l < r) {
            if (nums[i] + nums[l] + nums[r] >= sum)
                --r;
            else {
                res += r - l;
                ++l;
            }
        }
    }
    return res;
}


int main(int argc, char *argv[])
{
    int nums[] = {5, 1, 3, 4, 7};
    int sum = 12;
    int res = count_triplets_smaller_than_sum(nums, sizeof(nums) / sizeof(int), sum);
    printf("count: %d\n", res);

    return 0;
}
