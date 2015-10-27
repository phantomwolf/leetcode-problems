#ifndef _FIBONACCI_HEAP_H_
#define _FIBONACCI_HEAP_H_


#include <stdbool.h>
#include <stdint.h>

/* 斐波那契堆受到了二项堆的启发，但做了一些改动:
 *      - 斐波那契堆中的树可以是任何形状，不需要是二项树。
 *      - 二项堆每次insert、extract_min后都会进行一系列树的合并、分解操作，以维护二项堆的性质。
 *        斐波那契堆则采取懒惰的方法，仅当extract_min时才将树合并。
 *      - 斐波那契堆用一个指针，始终指向最小值
 *      - 树存放在环形、双向链表里
 */

#define swap(a, b) \
            do { typeof(a) __tmp = (a); (a) = (b); (b) = __tmp; } while (0)


typedef struct FibonacciNode FibonacciNode;
struct FibonacciNode {
    int32_t key;
    FibonacciNode *parent;
    FibonacciNode *child;
    FibonacciNode *left;
    FibonacciNode *right;
    int32_t degree;           // count of child nodes
    bool marked;            // A node is marked if at least one of its children was cut since this node was made a child of another node (all roots are unmarked)
};

void fibonacci_node_init(FibonacciNode *node);

FibonacciNode *heap_insert(FibonacciNode *min, int32_t key);

int32_t heap_min(FibonacciNode *min);

FibonacciNode *heap_extract_min(FibonacciNode *min);

void heap_consolidate_tree(FibonacciNode *min);

void tree_merge(FibonacciNode *tree1, FibonacciNode *tree2);

void heap_print(FibonacciNode *min);

#endif
