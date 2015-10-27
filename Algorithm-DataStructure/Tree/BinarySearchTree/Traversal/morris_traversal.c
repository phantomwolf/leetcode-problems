#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void morris_traversal(Tree *tree)
{
    printf("Morris traversal: ");
    Node *node = tree->root;
    while (node != NULL) {
        if (node->left == NULL) {
            printf("%d, ", node->data);
            node = node->right;
            continue;
        }
        Node *pre = node->left;
        while (pre->right != NULL && pre->right != node) {
            pre = pre->right;
        }
        if (pre->right == NULL) {
            pre->right = node;
            node = node->left;
        } else {
            pre->right = NULL;
            printf("%d, ", node->data);
            node = node->right;
        }
    }
    puts("");
}


int main(int argc, char *argv[])
{
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree_init(tree);

    // Insert data
    //                      20
    //                    /    \
    //                  15      25
    //                /   \      \
    //               10   18      30
    //                \
    //                 12
    //
    tree_insert(tree, 20);
    tree_insert(tree, 15);
    tree_insert(tree, 18);
    tree_insert(tree, 10);
    tree_insert(tree, 12);

    tree_insert(tree, 25);
    tree_insert(tree, 30);

    print_tree(tree->root);
    puts("");

    morris_traversal(tree);


    return 0;
}
