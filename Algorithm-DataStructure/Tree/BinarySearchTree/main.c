#include "bst.h"

#include <stdio.h>
#include <stdlib.h>


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

    return 0;
}
