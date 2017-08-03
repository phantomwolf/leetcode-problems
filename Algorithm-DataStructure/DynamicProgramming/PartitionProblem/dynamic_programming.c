#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool is_subset_sum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    if (sum % 2 != 0)
        return false;

    int target = sum / 2;
    // d[i][j] is true, if a subset of {arr[0], arr[1], ..., arr[j-1]} has sum equal to i
    bool d[target + 1][n + 1];
    for (int j = 0; j <= n; ++j)
        d[0][j] = true;
    for (int i = 1; i <= target; ++i)
        d[i][0] = false;
    for (int i = 1; i <= target; ++i) {
        for (int j = 1; j <= n; ++j) {
            d[i][j] = d[i][j - 1];
            if (i >= arr[j - 1])
                d[i][j] |= d[i - arr[j - 1]][j - 1];
        }
    }
    return d[target][n];
}

int main(int argc, char *argv[])
{
    int arr[] = {3, 1, 5, 9, 12};
    bool res = is_subset_sum(arr, sizeof(arr) / sizeof(int));
    printf("%d\n", res);

    return 0;
}
