#include <stdio.h>
#include <stddef.h>
#include <limits.h>


int lbs(int arr[], size_t n)
{
    int lis[n];
    int lds[n];
    lis[0] = lds[n - 1] = 1;
    for (int i = 1; i < n; ++i) {
        int max_lis = -1, max_lds = -1;
        for (int j = 0; j < i; ++j) {
            if (arr[i] >= arr[j] && max_lis < lis[j] + 1)
                max_lis = lis[j] + 1;
            if (arr[n - 1 - i] >= arr[n - 1 - j] && max_lds < lds[n - 1 - j] + 1)
                max_lds = lds[n - 1 - j] + 1;
        }
        lis[i] = max_lis;
        lds[n - 1 - i] = max_lds;
    }

    printf("lis: ");
    for (int i = 0; i < n; ++i) {
        printf("%d, ", lis[i]);
    }
    printf("\nlds: ");
    for (int i = 0; i < n; ++i) {
        printf("%d, ", lds[i]);
    }
    puts("");

    int max_lbs = INT_MIN;
    for (int i = 0; i < n; ++i) {
        int tmp = lis[i] + lds[i] - 1;
        if (max_lbs < tmp)
            max_lbs = tmp;
    }

    return max_lbs;
}


int main()
{
    //int arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
    //int arr[] = {12, 11, 40, 5, 3, 1};
    int arr[] = {80, 60, 30, 40, 20, 10};

    int res = lbs(arr, sizeof(arr) / sizeof(int));
    printf("result: %d\n", res);


    return 0;
}
