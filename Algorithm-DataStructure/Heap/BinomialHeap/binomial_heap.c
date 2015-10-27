#include <stdlib.h>
#include <stdio.h>

#include "binomial_heap.h"


void node_init(BinomialNode *node)
{
    node->degree = 0;
    node->child = node->sibling = NULL;
}

BinomialNode *node_merge(BinomialNode *node1, BinomialNode *node2)
{
    if (node1->key > node2->key)
        swap(node1, node2);
    node2->sibling = node1->child;
    node1->child = node2;
    node1->degree++;
    return node1;
}

BinomialNode *heap_union(BinomialNode *node1, BinomialNode *node2)
{
    if (node1 == NULL)
        return node2;
    else if (node2 == NULL)
        return node1;

    BinomialNode *head;
    if (node1->degree <= node2->degree) {
        head = node1;
        node1 = node1->sibling;
    } else {
        head = node2;
        node2 = node2->sibling;
    }

    // Simply merge 2 lists
    BinomialNode *node = head;
    while (node1 != NULL && node2 != NULL) {
        if (node1->degree <= node2->degree) {
            node->sibling = node1;
            node1 = node1->sibling;
        } else {
            node->sibling = node2;
            node2 = node2->sibling;
        }
        node = node->sibling;
    }
    // Handle remaining nodes
    if (node1 != NULL)
        node->sibling = node1;
    else if (node2 != NULL)
        node->sibling = node2;
    // Merge adjacent trees with the same degree
    node = head;
    BinomialNode *prev = NULL, *next = node->sibling;
    while (next->sibling != NULL) {
        // Case 1 & Case 2
        if (node->degree != next->degree || next->degree == next->sibling->degree) {
            prev = node;
            node = next;
            next = node->sibling;
            continue;
        }
        // Case 3 & Case 4
        next = next->sibling;
        node = node_merge(node, node->sibling);
        if (prev == NULL)
            head = node;
        else
            prev->sibling = node;
        node->sibling = next;
    }
    // Handle last 2 nodes
    if (node->degree == next->degree) {
        node = node_merge(node, next);
        if (prev == NULL)
            head = node;
        else
            prev->sibling = node;
        node->sibling = NULL;
    }
    return head;
}

BinomialNode *heap_insert(BinomialNode *heap, int32_t key)
{
    // Create a new binomial node with degree 0
    BinomialNode *node = (BinomialNode *)malloc(sizeof(BinomialNode));
    node_init(node);
    node->key = key;
    if (heap == NULL)
        return node;
    // Merge it into heap
    heap = heap_union(node, heap);
    return heap;
}

int32_t heap_min(BinomialNode *node)
{
    int32_t min = INT32_MAX;
    while (node != NULL) {
        if (node->key < min)
            min = node->key;
        node = node->sibling;
    }
    return min;
}

BinomialNode *heap_extract_min(BinomialNode *heap)
{
    int32_t min = INT32_MAX;
    BinomialNode *node_min = NULL, *node = heap, *prev = NULL;
    // Find the node which contains the minimal key
    while (node != NULL) {
        if (node->key < min) {
            min = node->key;
            prev = node_min;
            node_min = node;
        }
        node = node->sibling;
    }
    // Detach node_min from the original heap
    if (node_min == heap) {
        heap = node_min->sibling;
    } else {
        prev->sibling = node_min->sibling;
    }
    node_min->sibling = NULL;
    // Make a new heap(by reversing linked list)
    BinomialNode *next = node_min->child;
    free(node_min);

    node = NULL;
    while (next != NULL) {
        BinomialNode *tmp = next->sibling;
        next->sibling = node;
        node = next;
        next = tmp;
    }
    return heap_union(node, heap);
}

void print_heap(BinomialNode *node)
{
    printf("%d", node->key);
    if (node->child != NULL) {
        // print child tree
        printf("(");
        print_heap(node->child);
        printf(")");
    }
    if (node->sibling != NULL) {
        printf(",");
        print_heap(node->sibling);
    }
}
