#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void counting_sort(int A[], int n, int max)
{
    int *count = (int *)malloc(sizeof(int) * (max + 1));
    memset(count, 0, sizeof(int) * (max + 1));
    for (int i = 0; i < n; ++i) {
        count[A[i]]++;
    }
    // set count[i] = count[i] + count[i - 1]
    for (int i = 1; i < max + 1; ++i) {
        count[i] += count[i - 1];
    }
    // write results back to array
    for (int i = 0, j = 0; i < max + 1; ++i) {
        while (j != count[i]) {
            A[j++] = i;
        }
    }
    free(count);
}


int main(int argc, char *argv[])
{
    int A[] = {1, 4, 1, 2, 7, 5, 2};
    int n   = sizeof(A) / sizeof(int);
    printf("Before: ");
    for (int i = 0; i < n; ++i) {
        printf("%d, ", A[i]);
    }
    counting_sort(A, n, 10);
    printf("\nAfter:  ");
    for (int i = 0; i < n; ++i) {
        printf("%d, ", A[i]);
    }
    puts("");

    return 0;
}
