#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

Node *create_node(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
}

void tree_init(Tree *tree)
{
    tree->root = NULL;
}

void tree_insert(Tree *tree, int data)
{
    Node *new_node = create_node(data);
    if (tree->root == NULL) {
        tree->root = new_node;
        return;
    }
    Node *node = tree->root, *parent = NULL;
    while (node != NULL) {
        parent = node;
        if (new_node->data < node->data) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    if (new_node->data < parent->data)
        parent->left = new_node;
    else
        parent->right = new_node;
}

/* Print structure of tree by preorder traversal */
void print_tree(Node *node)
{
    printf("%d", node->data);
    if (node->left == NULL && node->right == NULL) {
        return;
    }
    printf("(");
    if (node->left != NULL) {
        print_tree(node->left);
    }
    if (node->right != NULL) {
        printf(",");
        print_tree(node->right);
    }
    printf(")");
}
