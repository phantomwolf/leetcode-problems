#include <stdio.h>
#include <string.h>

#include "heap.h"

struct Heap *heap_create(int capacity)
{
    struct Heap *heap = (struct Heap *)malloc(sizeof(struct Heap));
    if (heap == NULL)
        return NULL;
    if (!heap_init(heap, capacity)) {
        free(heap);
        return NULL;
    }
    return heap;
}

bool heap_init(struct Heap *heap, int capacity)
{
    heap->keys = (int *)malloc(sizeof(int) * capacity);
    if (heap->keys == NULL)
        return false;
    heap->capacity = capacity;
    heap->size = 0;
    return true;
}

struct Heap *heap_build(int array[], size_t size)
{
    struct Heap *heap = (struct Heap *)malloc(sizeof(struct Heap));
    heap_init(heap, size);
    heap->size = size;
    
    memcpy(heap->keys, array, sizeof(int) * size);

    // Heapify
    for (int i = size - 1; i >= 0; --i) {
        heap_heapify(heap, i);
    }
    return heap;
}

bool heap_resize(struct Heap *heap, int capacity)
{
    if (capacity < heap->size)
        return false;
    if (capacity == heap->capacity)
        return true;

    int *new_keys = (int *)realloc(heap->keys, sizeof(int) * capacity);
    if (new_keys == NULL)
        return false;
    fprintf(stderr, "Heap resize: %d => %d\n",
            heap->capacity, capacity);
    heap->keys = new_keys;
    heap->capacity = capacity;
    return true;
}

int heap_min(struct Heap *heap)
{
    if (heap->size == 0)
        return INT_MAX;
    return heap->keys[0];
}

int heap_extract_min(struct Heap *heap)
{
    if (heap->size == 0)
        return INT_MAX;
    int key = heap->keys[0];
    heap->keys[0] = heap->keys[--heap->size];
    heap_heapify(heap, 0);
    return key;
}

void heap_heapify(struct Heap *heap, int i)
{
    while (i < heap->size) {
        int min = i;
        if (heap_left(i) < heap->size && heap->keys[heap_left(i)] < heap->keys[min])
            min = heap_left(i);
        if (heap_right(i) < heap->size && heap->keys[heap_right(i)] < heap->keys[min])
            min = heap_right(i);
        if (min == i)
            break;
        swap(heap->keys[min], heap->keys[i]);
        i = min;
    }
}

bool heap_insert(struct Heap *heap, int key)
{
    static double factor = 1.5;
    if (heap->size == heap->capacity &&
        !heap_resize(heap, heap->capacity * factor + 1)) {
        // Heap resizing failed
        return false;
    }

    heap->keys[heap->size++] = key;

    int i = heap->size - 1;
    int p = heap_parent(i);
    while (i != 0 && heap->keys[i] < heap->keys[p]) {
        swap(heap->keys[i], heap->keys[p]);
        i = p;
        p = heap_parent(i);
    }
    return true;
}

void heap_decrease_key(struct Heap *heap, int i, int new_val)
{
    heap->keys[i] = new_val;
    int p = heap_parent(i);
    while (i != 0 && heap->keys[i] < heap->keys[p]) {
        printf("swap: %d <=> %d\n", p, i);
        swap(heap->keys[i], heap->keys[p]);
        i = p;
        p = heap_parent(i);
    }
}

void heap_delete_key(struct Heap *heap, int i)
{
    fprintf(stderr, "Deleting key at %d...\n", i);
    heap_decrease_key(heap, i, INT_MIN);
    heap_extract_min(heap);
}

void heap_print(struct Heap *heap)
{
    printf("heap: ");
    for (int i = 0; i < heap->size; ++i) {
        printf("%d(%d), ", heap->keys[i], i);
    }
    puts("");
}
