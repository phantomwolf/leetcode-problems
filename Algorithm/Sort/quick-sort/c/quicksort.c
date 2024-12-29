#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define SWAP(a, b) \
        do { typeof(a) __tmp = a; a = b; b = __tmp; } while (0)

void quick_sort_recursive(int nums[], int low, int high)
{
    int pivot = rand() % (high - low + 1) + low;
    SWAP(nums[pivot], nums[low]);

    int i = low;
    int j = high + 1;
    while (1) {
        do {
            i++;
        } while (i <= high && nums[i] < nums[low]);
        do {
            j--;
        } while (j > 0 && nums[j] > nums[low]);
        if (i >= j) {
            SWAP(nums[low], nums[j]);
            break;
        }
        SWAP(nums[i], nums[j]);
    }
    if (j - low > 1)
        quick_sort_recursive(nums, low, j - 1);
    if (high - j > 1)
        quick_sort_recursive(nums, j + 1, high);
}

void quick_sort(int nums[], int n)
{
    srand(time(NULL));
    quick_sort_recursive(nums, 0, n - 1);
}

int main(int argc, char *argv[])
{
    int nums[] = {3, 7, 5, 1, 2, 4, 8, 7, 3};
    int n = sizeof(nums) / sizeof(int);
    quick_sort(nums, n);

    for (int i = 0; i < n; i++) {
        printf("%d, ", nums[i]);
    }
    putchar('\n');
    return 0;
}
