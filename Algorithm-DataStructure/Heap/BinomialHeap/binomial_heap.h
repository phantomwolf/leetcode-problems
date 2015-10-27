#ifndef __BINOMIAL_HEAP_H__
#define __BINOMIAL_HEAP_H__

#include <stddef.h>
#include <stdint.h>

#define swap(a, b) \
        do { typeof(a) __tmp = (a); (a) = (b); (b) = __tmp; } while (0)

/* Example of binomial heap:
 *
 *      12 ----- 10 -------------------20
 *              / |                  / / |
 *             /  |                /  |  |
 *            15  50              70 50  40
 *             |                 / |  |
 *            30                80 85 65
 *                              |
 *                             100
 */

typedef struct BinomialNode BinomialNode;
struct BinomialNode {
    int32_t key;
    uint32_t degree;
    BinomialNode *child;
    BinomialNode *sibling;
};

/* Init BinomialNode */
void node_init(BinomialNode *node);

/* Merge 2 BinomialNode with the same degree */
BinomialNode *node_merge(BinomialNode *node1, BinomialNode *node2);

/* Merge 2 BinomialNode */
BinomialNode *heap_union(BinomialNode *node1, BinomialNode *node2);

BinomialNode * heap_insert(BinomialNode *heap, int32_t key);

int32_t heap_min(BinomialNode *node);

BinomialNode *heap_extract_min(BinomialNode *node);

void heap_delete(BinomialNode *heap, int32_t key);

void heap_decrease_key(BinomialNode *heap, int32_t key, int32_t new_val);

void print_heap(BinomialNode *heap);

#endif
