#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define swap(a, b) \
        do { int __tmp = a; a = b; b = __tmp; } while (0)


int partition(int array[], int left, int right)
{
    if (left == right)
        return left;
    // random pivot
    int pivot = left + rand() % (right - left + 1);
    printf("pivot tmp: %d\n", pivot);
    if (pivot != left)
        swap(array[pivot], array[left]);

    int i = left, j = right + 1;
    while (1) {
        do {
            ++i;
        } while (i <= right && array[i] < array[left]);
        do {
            --j;
        } while (array[j] > array[left]);
        if (i >= j) {
            swap(array[left], array[j]);
            return j;
        }
        if (array[i] != array[j]) {
            swap(array[i], array[j]);
        }
    }
}


void quick_sort_iterative(int array[], int left, int right)
{
    int stack[right - left + 1];
    int top = -1;
    stack[++top] = left;
    stack[++top] = right;
    while (top >= 0) {
        right = stack[top--];
        left = stack[top--];

        int pivot = partition(array, left, right);
        printf("pivot: %d\n", pivot);
        int left_len = pivot - left;
        int right_len = right - pivot;
        if (left_len > 1) {
            stack[++top] = left;
            stack[++top] = pivot - 1;
        }
        if (right_len > 1) {
            stack[++top] = pivot + 1;
            stack[++top] = right;
        }
    }
}

int main (int argc, char *argv[])
{
    srand(time(NULL));
    
    int array[] = {3, 7, 6, 9, 4, 2, 8, 7, 5, 9, 1};
    for (int i = 0; i < sizeof(array) / sizeof(int); ++i) {
        printf("%d, ", array[i]);
    }
    puts("");

    quick_sort_iterative(array, 0, sizeof(array) / sizeof(int) - 1);

    for (int i = 0; i < sizeof(array) / sizeof(int); ++i) {
        printf("%d, ", array[i]);
    }
    puts("");
    return 0;
}
