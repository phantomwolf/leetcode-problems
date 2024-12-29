#include "fibonacci_heap.h"

#include <stdlib.h>
#include <stdio.h>


int main()
{
    int keys[8] = {83, 86, 77, 15, 93, 35, 85, 92};
    int32_t min_key;

    FibonacciNode *heap = NULL;
    heap = heap_insert(heap, 8);

    min_key = heap_min(heap);
    printf("min: %d\n", min_key);

    return 0;
}
