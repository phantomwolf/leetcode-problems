#include <stdio.h>
#include <stdlib.h>
#include "rbtree.h"


int main(int argc, char *argv[])
{
    RB_TREE *tree;
    RB_NODE *node;
    int keys[7] = {1, 3, 8, 9, 4, 7, 2};
    tree = (RB_TREE *)malloc(sizeof(RB_TREE));
    rb_tree_init(tree);

    for (int i=0; i < 7; ++i) {
        node = (RB_NODE *)malloc(sizeof(RB_NODE));
        node->key = keys[i];
        rb_insert(tree, node);
    }
    print_tree(tree);

    RB_NODE *z = rb_find(tree, 8);
    printf("z key: %d\n", z->key);
    RB_NODE *y = rb_delete(tree, z);
    free(y);

    print_tree(tree);

    return 0;
}
