#include <stdio.h>

int smallest_integer(int nums[], size_t n)
{
    int sum = nums[0];
    for (int i = 1; i < n; ++i) {
        if (nums[i] > sum + 1)
            return sum + 1;
        sum += nums[i];
    }
    return sum + 1;
}


int main (int argc, char *argv[])
{
    int arr1[] = {1, 3, 4, 5};
    printf("arr1: %d\n", smallest_integer(arr1, sizeof(arr1) / sizeof(int)));

    int arr2[] = {1, 2, 6, 10, 11, 15};
    printf("arr2: %d\n", smallest_integer(arr2, sizeof(arr2) / sizeof(int)));

    int arr3[] = {1, 1, 1, 1};
    printf("arr3: %d\n", smallest_integer(arr3, sizeof(arr3) / sizeof(int)));

    int arr4[] = {1, 1, 3, 4};
    printf("arr4: %d\n", smallest_integer(arr4, sizeof(arr4) / sizeof(int)));

}
