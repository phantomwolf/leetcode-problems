/* Binary Search Tree */
#ifndef _BST_H
#define _BST_H

typedef struct Node Node;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

Node *create_node(int data);

typedef struct Tree Tree;

struct Tree {
    struct Node *root;
};

void tree_init(Tree *tree);

void tree_insert(Tree *tree, int data);

void print_tree(Node *node);

#endif
