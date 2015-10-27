#include "heap.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>

int compar(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
        return 1;
    else if (*(int *)a < *(int *)b)
        return -1;
    else
        return 0;
}

int **gen_k_sorted_array(size_t k, size_t n)
{
    srand(time(NULL));
    int **arrays = (int **)malloc(sizeof(int *) * k);
    for (int i = 0; i < k; ++i) {
        arrays[i] = (int *)malloc(sizeof(int) * n);
        printf("%d: ", i);
        for (int j = 0; j < n; ++j) {
            arrays[i][j] = rand() % 10000;
        }
        qsort(arrays[i], n, sizeof(int), compar);
        for (int j = 0; j < n; ++j) {
            printf("%d, ", arrays[i][j]);
        }
        puts("");
    }
    return arrays;
}

/* Merge k sorted arrays, each with n elements */
int *merge_k_sorted_array(int **arrays, size_t k, size_t n)
{
    struct MinHeapNode *nodes = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode) * k);
    for (int i = 0; i < k; ++i) {
        nodes[i].key = arrays[i][0];
        nodes[i].array = arrays[i];
        nodes[i].index = 0;
    }
    struct MinHeap *heap = heap_build(nodes, k);

    int *result = (int *)malloc(sizeof(int) * n * k);
    for (int i = 0; i < k * n; ++i) {
        struct MinHeapNode *node = heap_min(heap);
        result[i] = node->key;
        ++node->index;
        if (node->index == n)
            node->key = INT_MAX;
        else
            node->key = node->array[node->index];
        heap_heapify(heap, 0);
    }
    return result;
}

int main(int argc, char *argv[])
{
    int k = 7;
    int n = 10;
    int **arrays = gen_k_sorted_array(k, n);
    int *result = merge_k_sorted_array(arrays, k, n);

    printf("result: ");
    for (int i = 0; i < n * k; ++i) {
        printf("%d, ", result[i]);
    }
    puts("");

    // Veryfy result
    for (int i = 1; i < n * k; ++i) {
        if (result[i-1] > result[i]) {
            puts("FAIL!!!");
            exit(1);
        }
    }


    return 0;
}
