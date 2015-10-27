#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define ARRAY_SIZE  3

#define swap(a, b) do { int __tmp = (a); (a) = (b); (b) = __tmp; } while (0)


int partition(int array[], int l, int r)
{
    int p = rand() % (r - l + 1) + l;
    int tmp = array[p];
    array[p] = array[l];
    array[l] = tmp;

    int i = l + 1, j = r;
    while (1) {
        while (array[i] > array[l]) {
            ++i;
        }
        while (array[j] < array[l]) {
            --j;
        }
        if (i >= j) {
            tmp = array[l];
            array[l] = array[j];
            array[j] = tmp;
            break;
        }
        if (array[i] != array[j]) {
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
        ++i;
        --j;
    }
    return j;
}

int findKthLargest(int *nums, int numsSize, int k)
{
    int l = 0, r = numsSize - 1;
    int pivot = partition(nums, l, r);
    while (pivot != k - 1) {
        if (pivot < k - 1) {
            l = pivot + 1;
        } else {
            r = pivot - 1;
        }
        pivot = partition(nums, l, r);
    }
    return nums[pivot];
}

int main()
{
    srand(time(NULL));

    int array[ARRAY_SIZE] = {-1, 2, 0};

    int k = 2;
    int result = findKthLargest(array, ARRAY_SIZE, k);
    printf("%dth largest: %d\n", k, result);

    return 0;
}
