#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "binomial_heap.h"

int main(int argc, char *argv[])
{
    //int array[8] = {83, 86, 77, 15, 93, 35, 85, 92};
    //size_t length = 8;
    int array[7] = {83, 86, 77, 15, 93, 35, 85};
    size_t length = 7;

    BinomialNode *heap = NULL;
    for (int i = 0; i < length; ++i) {
        heap = heap_insert(heap, array[i]);
    	print_heap(heap);
        puts("\n");
    }
    // Print the minimal key
    printf("min: %d\n", heap_min(heap));
    // Extract min
    heap = heap_extract_min(heap);
    print_heap(heap);
    puts("");

    return 0;
}
