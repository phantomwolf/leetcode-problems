#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define ARRAY_SIZE  2


#define swap(a, b) \
        do { typeof(a) __tmp = a; a = b; b = __tmp; } while (0)


void print_array(int array[], int size, int l, int r, int p)
{
    int i = 0;
    while (i < l) {
        printf("%3d", array[i]);
        ++i;
    }
    printf("[");
    while (i < p) {
        printf("%3d", array[i]);
        ++i;
    }
    printf(" |%d| ", array[i]);
    ++i;
    while (i <= r) {
        printf("%3d", array[i]);
        ++i;
    }
    printf("]");
    while (i < size) {
        printf("%3d", array[i]);
        ++i;
    }
    puts("");
}


// Choose median of first, last, middle elements as pivot
int partition(int array[], int l, int r)
{
    if (l > r)
        return -1;
    if (l == r)
        return l;

    int p = rand() % (r - l + 1) + l;
    // Place pivot to the last position
    swap(array[p], array[r]);

    int i = l, j = r;
    while (j != r) {
        if (array[j] < array[r]) {
            if (j != i)
                swap(array[j], array[i]);
            ++i;
        }
        ++j;
    }
    swap(array[i], array[r]);
    return i;
}

int kth_smallest(int array[], size_t size, int k)
{
    if (k > size) {
        return -1;
    }

    int l = 0, r = size - 1;
    int pivot = partition(array, l, r);
    while (pivot != k - 1) {
        // Print l, r, pivot
        printf("%-3d %-3d %-3d:  ", l, pivot, r);
        print_array(array, ARRAY_SIZE, l, r, pivot);
        sleep(1);
        if (pivot < k - 1) {
            l = pivot + 1;
        } else {
            r = pivot - 1;
        }
        pivot = partition(array, l, r);
    }
    return pivot;
}

int main()
{
    srand(time(NULL));

    int pivot;
    int array[ARRAY_SIZE];
    printf("before: ");
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        array[i] = rand() % 100;
        printf("%3d, ", array[i]);
    }
    puts("");
/*
    pivot = partition(array, 0, ARRAY_SIZE - 1);

    printf("\nafter:  ");
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        printf("%3d, ", array[i]);
    }
    printf("\npivot: %d\n", pivot);*/

    int k = 1;
    int index = kth_smallest(array, ARRAY_SIZE, k);
    if (index == -1) {
        printf("Failed to find %dth smallest element of array: ", k);
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            printf("%4d", array[i]);
        }
        puts("");
        exit(1);
    } else {
        printf("%dth smallest: %d\n", k, array[index]);
    }

    return 0;
}
