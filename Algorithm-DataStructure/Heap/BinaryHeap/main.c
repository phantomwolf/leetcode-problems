#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#include "heap.h"

int main(int argc, char *argv[])
{
    srand(time(NULL));

    int array[10];
    for (int i = 0; i < 10; ++i) {
        array[i] = rand() % 100;
    }
    // Build heap from the array
    struct Heap *heap = heap_build(array, 10);
    printf("Heap sort: ");
    while (heap->size != 0) {
        printf("%-5d", heap_extract_min(heap));
    }
    puts("");

    return 0;
}
