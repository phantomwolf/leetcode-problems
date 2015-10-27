/*红黑树的性质：
 *  1.每个结点或者是红的，或者是黑的
 *  2.根结点是黑的
 *  3.每个叶结点(NIL)是黑的
 *  4.如果一个结点是红的，则它的两个儿子都是黑的。
 *  5.对每个结点，从该结点到其他子孙结点的所有路径上包含相同数目的黑结点
 */
#ifndef _RBTREE_H
#define _RBTREE_H

#define RB_BLACK    1
#define RB_RED      0

#include <stddef.h>

struct rb_tree {
    struct rb_node *root;
    struct rb_node *nil;
};

typedef struct rb_tree RB_TREE;

struct rb_node {
    int key;
    int color;
    struct rb_node *lchild, *rchild, *parent;
};

typedef struct rb_node RB_NODE;


void print_tree(RB_TREE *tree);
RB_NODE *rb_successor(RB_TREE *tree, RB_NODE *z);
void rb_left_rotate(RB_TREE *tree, RB_NODE *x);
void rb_right_rotate(RB_TREE *tree, RB_NODE *y);
RB_NODE *rb_find(RB_TREE *tree, int key);
void rb_tree_init(RB_TREE *tree);
void rb_tree_destroy(RB_TREE *tree);
void rb_insert(RB_TREE *tree, RB_NODE *z);
void rb_insert_fixup(RB_TREE *tree, RB_NODE *node);
RB_NODE *rb_delete(RB_TREE *tree, RB_NODE *z);
void rb_delete_fixup(RB_TREE *tree, RB_NODE *z);

#endif
