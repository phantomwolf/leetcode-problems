#ifndef _HEAP_H_
#define _HEAP_H_


#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#define swap(a, b) \
        do { typeof(a) __tmp = (a); (a) = (b); (b) = __tmp; } while (0)


// 设堆的数组起始下标为0
#define heap_left(i)                    (2*(i)+1)
#define heap_right(i)                   (2*(i)+2)
#define heap_parent(i)                  (((i)-1)/2)

// 最小堆
struct Heap {
    int size;               // current amount of elements
    int capacity;           // maximum amount of elements unless resized
    int *keys;              // the array which stores all the keys
};

/* Build a heap from an array */
struct Heap *heap_build(int array[], size_t size);

/* Create an empty heap */
struct Heap *heap_create(int capacity);

/* Init a heap structure */
bool heap_init(struct Heap *heap, int capacity);

/* Resize the capacity of heap */
bool heap_resize(struct Heap *heap, int new_size);

/* Insert key into heap */
bool heap_insert(struct Heap *heap, int key);

/* Return the minimum value */
int heap_min(struct Heap *heap);

/* Extract the minimum value */
int heap_extract_min(struct Heap *heap);

/* Decrease value of key at index i */
void heap_decrease_key(struct Heap *heap, int i, int new_val);

/* Remove key */
void heap_delete_key(struct Heap *heap, int i);

/* Maintain heap property */
void heap_heapify(struct Heap *heap, int i);

/* Print all the elements inside heap */
void heap_print(struct Heap *heap);


#endif
