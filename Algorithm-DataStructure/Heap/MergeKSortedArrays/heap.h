#ifndef _HEAP_H_
#define _HEAP_H_


#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <stddef.h>

#define swap(a, b) \
        do { typeof(a) __tmp = (a); (a) = (b); (b) = __tmp; } while (0)


// 设堆的数组起始下标为0
#define heap_left(i)                    (2*(i)+1)
#define heap_right(i)                   (2*(i)+2)
#define heap_parent(i)                  (((i)-1)/2)

struct MinHeapNode {
    int key;
    int *array;
    int index;
};

// 最小堆
struct MinHeap {
    int size;               // current amount of elements
    int capacity;           // maximum amount of elements unless resized
    struct MinHeapNode *nodes;
};

/* Build a heap from an array */
struct MinHeap *heap_build(struct MinHeapNode *nodes, size_t size);

/* Create an empty heap */
struct MinHeap *heap_create(int capacity);

/* Init a heap structure */
bool heap_init(struct MinHeap *heap, int capacity);

/* Resize the capacity of heap */
bool heap_resize(struct MinHeap *heap, int new_size);

/* Insert data into heap */
bool heap_insert(struct MinHeap *heap, int key, int *array, int index);

/* Return the minimum value */
struct MinHeapNode *heap_min(struct MinHeap *heap);

/* Extract the minimum value */
void heap_extract_min(struct MinHeap *heap);

/* Decrease value of data at index i */
void heap_decrease_key(struct MinHeap *heap, int i, int new_val);

/* Remove data */
void heap_delete_key(struct MinHeap *heap, int i);

/* Maintain heap property */
void heap_heapify(struct MinHeap *heap, int i);

/* Print all the elements inside heap */
void heap_print(struct MinHeap *heap);


#endif
