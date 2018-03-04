#include <stdio.h>
#include <string.h>

#include "heap.h"

struct MinHeap *heap_create(int capacity)
{
    struct MinHeap *heap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    if (heap == NULL)
        return NULL;
    if (!heap_init(heap, capacity)) {
        free(heap);
        return NULL;
    }
    return heap;
}

bool heap_init(struct MinHeap *heap, int capacity)
{
    heap->nodes = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode) * capacity);
    if (heap->nodes == NULL)
        return false;
    heap->capacity = capacity;
    heap->size = 0;
    return true;
}

struct MinHeap *heap_build(struct MinHeapNode *nodes, size_t size)
{
    struct MinHeap *heap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    heap->capacity = heap->size = size;
    heap->nodes = nodes;
    // Heapify
    for (int i = size - 1; i >= 0; --i) {
        heap_heapify(heap, i);
    }
    return heap;
}

bool heap_resize(struct MinHeap *heap, int capacity)
{
    if (capacity < heap->size)
        return false;
    if (capacity == heap->capacity)
        return true;

    struct MinHeapNode *nodes = (struct MinHeapNode *)realloc(heap->nodes, sizeof(struct MinHeapNode) * capacity);
    if (nodes == NULL)
        return false;
    fprintf(stderr, "Heap resize: %d => %d\n",
            heap->capacity, capacity);
    heap->nodes = nodes;
    heap->capacity = capacity;
    return true;
}

struct MinHeapNode *heap_min(struct MinHeap *heap)
{
    if (heap->size == 0)
        return NULL;
    return &heap->nodes[0];
}

void heap_extract_min(struct MinHeap *heap)
{
    if (heap->size <= 1) {
        heap->size = 0;
        return;
    }
    --heap->size;
    heap->nodes[0].key = heap->nodes[heap->size].key;
    heap->nodes[0].array = heap->nodes[heap->size].array;
    heap->nodes[0].index = heap->nodes[heap->size].index;
    heap_heapify(heap, 0);
}

void heap_heapify(struct MinHeap *heap, int i)
{
    while (i < heap->size) {
        int min = i;
        if (heap_left(i) < heap->size && heap->nodes[heap_left(i)].key < heap->nodes[min].key)
            min = heap_left(i);
        if (heap_right(i) < heap->size && heap->nodes[heap_right(i)].key < heap->nodes[min].key)
            min = heap_right(i);
        if (min == i)
            break;
        swap(heap->nodes[min].key, heap->nodes[i].key);
        swap(heap->nodes[min].array, heap->nodes[i].array);
        swap(heap->nodes[min].index, heap->nodes[i].index);
        i = min;
    }
}

bool heap_insert(struct MinHeap *heap, int key, int *array, int index)
{
    static double factor = 1.5;
    if (heap->size == heap->capacity &&
        !heap_resize(heap, heap->capacity * factor + 1)) {
        // Heap resizing failed
        return false;
    }

    ++heap->size;
    heap->nodes[heap->size].key = key;
    heap->nodes[heap->size].array = array;
    heap->nodes[heap->size].index = index;

    int i = heap->size - 1;
    int p = heap_parent(i);
    while (i != 0 && heap->nodes[i].key < heap->nodes[p].key) {
        swap(heap->nodes[i].key, heap->nodes[p].key);
        swap(heap->nodes[i].array, heap->nodes[p].array);
        swap(heap->nodes[i].index, heap->nodes[p].index);
        i = p;
        p = heap_parent(i);
    }
    return true;
}

void heap_decrease_key(struct MinHeap *heap, int i, int new_val)
{
    heap->nodes[i].key = new_val;
    int p = heap_parent(i);
    while (i != 0 && heap->nodes[i].key < heap->nodes[p].key) {
        printf("swap: %d <=> %d\n", p, i);
        swap(heap->nodes[i].key, heap->nodes[p].key);
        swap(heap->nodes[i].array, heap->nodes[p].array);
        swap(heap->nodes[i].index, heap->nodes[p].index);
        i = p;
        p = heap_parent(i);
    }
}

void heap_delete_key(struct MinHeap *heap, int i)
{
    fprintf(stderr, "Deleting key at %d...\n", i);
    heap_decrease_key(heap, i, INT_MIN);
    heap_extract_min(heap);
}

void heap_print(struct MinHeap *heap)
{
    printf("heap: ");
    for (int i = 0; i < heap->size; ++i) {
        printf("%d(%d), ", heap->nodes[i].key, i);
    }
    puts("");
}
