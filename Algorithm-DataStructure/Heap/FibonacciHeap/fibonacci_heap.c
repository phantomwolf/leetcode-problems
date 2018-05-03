#include "fibonacci_heap.h"

#include <stddef.h>
#include <stdlib.h>


void fibonacci_node_init(FibonacciNode *node)
{
    node->parent = node->child = NULL;
    node->left = node->right = node;
    node->degree = 0;
    node->marked = false;
}

FibonacciNode *heap_insert(FibonacciNode *min, int32_t key)
{
    // Create a new node
    FibonacciNode *node = (FibonacciNode *)malloc(sizeof(FibonacciNode));
    fibonacci_node_init(node);
    node->key = key;

    // If heap is empty
    if (min == NULL) {
        return node;
    }
    // Otherwise, insert node into circular list
    FibonacciNode *prev = min->left;
    prev->right = node;
    node->left = prev;
    node->right = min;
    min->left = node;
    if (min->key > node->key)
        min = node;
    return min;
}

int32_t heap_min(FibonacciNode *min)
{
    return min->key;
}

FibonacciNode *heap_extract_min(FibonacciNode *min)
{
    FibonacciNode *left = min->left, *right = min->right;
    if (min->child != NULL) {
        // Add child circular list to heap
        FibonacciNode *start = min->child, *end = min->child->left;
        FibonacciNode *node = start;
        do {
            node->parent = NULL;
            node = node->right;
        } while (node != start);
        left->right = start;
        start->left = left;
        right->left = end;
        end->right = right;
    }
    // Update min
    free(min);
    int32_t min_key = INT32_MAX;
    FibonacciNode *node = left;
    do {
        if (node->key < min_key) {
            min_key = node->key;
            min = node;
        }
        node = node->right;
    } while (node != left);
    // Consolidate tree
    heap_consolidate_tree(min);
    return min;
}

void tree_merge(FibonacciNode *tree1, FibonacciNode *tree2)
{
    if (tree1->key > tree2->key)
        swap(tree1, tree2);
    tree1->degree++;
    tree2->parent = tree1;
    if (tree1->child == NULL) {
        tree1->child = tree2;
        tree2->left = tree2->right = tree2;
        return;
    }
    tree2->right = tree1->child;
    tree2->left  = tree1->child->left;
    tree1->child->left->right = tree2;
    tree1->child->left = tree2;
}

void heap_consolidate_tree(FibonacciNode *min)
{
    FibonacciNode *degrees[32] = {0};
    FibonacciNode *node = min;
    do {
        FibonacciNode *prev = degrees[node->degree];
        while (prev != NULL) {
            // Detach prev
            prev->left->right = prev->right;
            prev->right->left = prev->left;
            // If prev is less than node, replace node
            if (prev->key < node->key) {
                node->left->right = prev;
                node->right->left = prev;
                prev->left = node->left;
                prev->right = node->right;
                swap(node, prev);
            }
            // Merge 2 trees
            tree_merge(node, prev);
            prev = degrees[node->degree];
        }
        degrees[node->degree] = node;

        node = node->right;
    } while (node != min);
}

void heap_print(FibonacciNode *min)
{
}
