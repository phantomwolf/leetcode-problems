#include <stdio.h>
#include <limits.h>

int shortest_subarray (int nums[], size_t n, int k)
{
    int sum = 0;
    int shortest = INT_MAX;
    int l = 0, r = 0;
    while (r < n) {
        while (r < n && sum <= k) {
            sum += nums[r++];
            if (sum <= 0) {
                l = r;
                sum = 0;
            }
        }
        if (r == n)
            break;
        while (l <= r && sum > k) {
            sum -= nums[l++];
        }
        if (l > r)
            break;
        if (shortest > r - l + 1)
            shortest = r - l + 1;
    }
    if (shortest == INT_MAX)
        return -1;
    return shortest;
}


int main (int argc, char *argv[])
{
    int arr1[] = {1, 4, 45, 6, 0, 19};
    printf ("arr1[]: %d\n", shortest_subarray (arr1, sizeof(arr1)/sizeof(int), 51));

    int arr2[] = {1, 10, 5, 2, 7};
    printf ("arr2[]: %d\n", shortest_subarray (arr2, sizeof(arr2)/sizeof(int), 9));

    int arr3[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
    printf ("arr3[]: %d\n", shortest_subarray (arr3, sizeof(arr3)/sizeof(int), 280));

    int arr4[] = {1, 2, 4};
    printf ("arr4[]: %d\n", shortest_subarray (arr4, sizeof(arr4)/sizeof(int), 8));

    int arr5[] = {-8, 1, 4, 2, -6};
    printf ("arr5[]: %d\n", shortest_subarray (arr5, sizeof(arr5)/sizeof(int), 6));

    return 0;
}
