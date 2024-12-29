#include <glib.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

bool is_complete_tree(Tree *tree)
{
    GQueue *queue = g_queue_new();

    bool is_complete = true;
    bool is_leaf = false;
    g_queue_push_tail(queue, tree->root);
    while (!g_queue_is_empty(queue)) {
        Node *node = g_queue_pop_head(queue);
        if (is_leaf == true) {
            if (node->left || node->right) {
                is_complete = false;
		printf("Not complete since node %d has one or more children\n", node->data);
		break;
            }
        } else if (node->left == NULL || node->right == NULL) {
            is_leaf = true;
            if (node->left == NULL && node->right != NULL) {
                is_complete = false;
		printf("Not complete since node %d has no left child but has a right child\n", node->data);
                break;
            }
        }
        if (node->left)
            g_queue_push_tail(queue, node->left);
        if (node->right)
            g_queue_push_tail(queue, node->right);
    }

    g_queue_clear(queue);
    g_queue_free(queue);
    return is_complete;
}

int main(int argc, char *argv[])
{
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree_init(tree);

    //                      20
    //                    /    \
    //                  15      25
    //                 /  \    /
    //                10  18  23
    //                  \
    //                  12
    //
    tree_insert(tree, 20);
    tree_insert(tree, 15);
    tree_insert(tree, 18);
    tree_insert(tree, 10);
    tree_insert(tree, 12);

    tree_insert(tree, 25);
    tree_insert(tree, 23);

    print_tree(tree->root);
    puts("");

    if (is_complete_tree(tree)) {
        puts("Is a complete tree!");
    } else {
        puts("Not a complete tree!");
    }

    //                      20
    //                    /    \
    //                  15      25
    //                /   \     / \
    //               10   18   23 30
    //                \
    //                 12
    //
    tree_insert(tree, 30);

    print_tree(tree->root);
    puts("");

    if (is_complete_tree(tree)) {
        puts("Is a complete tree!");
    } else {
        puts("Not a complete tree!");
    }

    //                      20
    //                    /    \
    //                  15      25
    //                 /  \    /  \
    //                10  18  23  30
    //               /  \
    //              9   12
    //
    tree_insert(tree, 9);

    print_tree(tree->root);
    puts("");

    if (is_complete_tree(tree)) {
        puts("Is a complete tree!");
    } else {
        puts("Not a complete tree!");
    }

    return 0;
}
