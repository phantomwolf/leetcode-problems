#include "rbtree.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void _print_tree(RB_TREE *tree, RB_NODE *node, int depth)
{
    if (node == tree->nil)
        return;
    putchar('|');
    for (int i = 1; i <= depth; ++i) {
        printf("==");
    }
    char color = (node->color == RB_BLACK) ? 'B' : 'R';
    printf("%d(%c)\n", node->key, color);
    _print_tree(tree, node->lchild, depth + 1);
    _print_tree(tree, node->rchild, depth + 1);
}

void print_tree(RB_TREE *tree)
{
    //_print_tree(tree, tree->root, 0);
    RB_NODE *queue[32];
    RB_NODE *begin, *end;
    begin = end = queue[0];
    *end = tree->root;
    ++end;
    while (begin != end) {
        char color = (*begin)->color == RB_BLACK ? 'B' : 'R';
        if (*begin == tree->nil)
            printf(" null");
        else
            printf("%5d%c", (*begin)->key, color);
        if ((*begin)->lchild != tree->nil) {
            *end = (*begin)->lchild;
            ++end;
        }
        if ((*begin)->rchild != tree->nil) {
            *end = (*begin)->rchild;
            ++end;
        }
        ++begin;
    }
}

RB_NODE *rb_successor(RB_TREE *tree, RB_NODE *z)
{
    RB_NODE *x;
    if (z->rchild != tree->nil) {
        x = z->rchild;
        while (x->lchild != tree->nil)
            x = x->lchild;
        return x;
    }
    x = z->parent;
    while (x != tree->nil && x->rchild == z) {
        z = x;
        x = z->parent;
    }
    return x;
}

void rb_tree_init(RB_TREE *tree)
{
    tree->nil = (RB_NODE *)malloc(sizeof(RB_NODE));
    tree->nil->lchild = tree->nil->rchild = tree->nil->parent = tree->nil;
    tree->nil->color = RB_BLACK;
    tree->root = tree->nil;
}

void rb_left_rotate(RB_TREE *tree, RB_NODE *x)
{
    RB_NODE *y = x->rchild;
    x->rchild = y->lchild;
    if (y->lchild != tree->nil)
        y->lchild->parent = x;
    y->lchild = x;
    y->parent = x->parent;
    if (x->parent == tree->nil)
        tree->root = y;
    else if (x == x->parent->lchild)
        x->parent->lchild = y;
    else
        x->parent->rchild = y;
    x->parent = y;
}

void rb_right_rotate(RB_TREE *tree, RB_NODE *y)
{
    RB_NODE *x = y->lchild;
    y->lchild = x->rchild;
    if (x->rchild != tree->nil)
        x->rchild->parent = y;
    x->rchild = y;
    x->parent = y->parent;
    if (y->parent == tree->nil)
        tree->root = x;
    else if (y == y->parent->lchild)
        y->parent->lchild = x;
    else
        y->parent->rchild = x;
    y->parent = x;
}

RB_NODE *rb_find(RB_TREE *tree, int key)
{
    RB_NODE *z = tree->root;
    while (z != tree->nil) {
        if (key == z->key)
            return z;
        else if (key < z->key)
            z = z->lchild;
        else
            z = z->rchild;
    }
    return z;
}

void rb_insert(RB_TREE *tree, RB_NODE *z)
{
    printf("Inserting %d...\n", z->key);
    RB_NODE *y = tree->nil;
    RB_NODE *x = tree->root;
    while (x != tree->nil) {
        y = x;
        if (z->key < x->key)
            x = x->lchild;
        else
            x = x->rchild;
    }
    z->parent = y;
    if (y == tree->nil)
        tree->root = z;
    else if (z->key < y->key)
        y->lchild = z;
    else
        y->rchild = z;
    z->lchild = z->rchild = tree->nil;
    z->color = RB_RED;
    rb_insert_fixup(tree, z);
}

void rb_insert_fixup(RB_TREE *tree, RB_NODE *z)
{
    RB_NODE *y;
    while (z->parent->color == RB_RED) {
        if (z->parent == z->parent->parent->lchild) {
            y = z->parent->parent->rchild;
            if (y->color == RB_RED) {
                z->parent->color = RB_BLACK;
                y->color = RB_BLACK;
                y->parent->color = RB_RED;
                z = y->parent;
            } else {
                if (z == z->parent->rchild) {
                    z = z->parent;
                    rb_left_rotate(tree, z);
                }
                z->parent->color = RB_BLACK;
                z->parent->parent->color = RB_RED;
                rb_right_rotate(tree, z->parent->parent);
            }
        } else {
            y = z->parent->parent->lchild;
            if (y->color == RB_RED) {
                z->parent->color = RB_BLACK;
                y->color = RB_BLACK;
                y->parent->color = RB_RED;
                z = y->parent;
            } else {
                if (z == z->parent->lchild) {
                    z = z->parent;
                    rb_right_rotate(tree, z);
                }
                z->parent->color = RB_BLACK;
                z->parent->parent->color = RB_RED;
                rb_left_rotate(tree, z->parent->parent);
            }
        }
    }
    tree->root->color = RB_BLACK;
}

/* z是目标结点，y是要删除的结点，x是y的子结点。
 * 如果z只有一个子结点，则要删除的结点就是z本身，即y == z;
 * 如果z有两个结点，比起删除z，删除z的后继y(至多有一个子结点)会比较容易。我们可以将y的数据复制到z中，然后删除y。
 * 不管哪种情况，删除y后用x来代替。
 */

RB_NODE *rb_delete(RB_TREE *tree, RB_NODE *z)
{
    RB_NODE *x, *y;
    if (z->lchild == tree->nil || z->rchild == tree->nil) {
        y = z;
    } else {
        y = rb_successor(tree, z);
        printf("successor of %d is %d\n", z->key, y->key);
    }
    /* 如果y等于z，那么x是z的一个子结点；如果y是z的后继，那么x是y的替代品，即y的子结点 */
    if (y->lchild != tree->nil)
        x = y->lchild;
    else
        x = y->rchild;
    /* First, we use x to replace y */
    x->parent = y->parent;
    /* If y is root */
    if (y->parent == tree->nil)
        tree->root = x;
    else if (y == y->parent->lchild)
        y->parent->lchild = x;
    else
        y->parent->rchild = x;
    /* Now, y has been removed from the tree, but we can still access it through y */
    /* Second, if y != z, use y to replace z by copying the key & data from y to z */
    if (y != z) {
        z->key = y->key;
    }
    if (y->color == RB_BLACK)
        rb_delete_fixup(tree, x);
    return y;
}


/* 如果被删除的结点y是黑色，会产生三个问题：
 * 1.如果y原来是root，而y的一个红结点x代替了它，则违反性质(2)。
 * 2.如果x和p[y]均为红色，则违反性质(4)
 * 3.删除y将导致先前包含y的任何路径上黑结点的数量减少1，破坏了性质(5)。
 *
设w为x的兄弟结点，p为x和w共同的父结点，以p为root的子树是我们所要考虑的所有范围，所以对这个树的改动都不会对整个树的其他部分产生影响。简称这个树的根结点为root。一开始，p == root。假定x在root左子树上。
关于结点的删除，有两种解释方法。
如果被删除的结点y是黑色，将其删除后，我们把y的黑色加到它的替代品x上。如果x原本也是黑色，那么x现在有2层黑色，这不符合红黑树的性质。
修复方法：
    1.若w是红色(那么w的子结点必定是黑色)，将p左旋，可让x获得一个新的、黑色的兄弟结点，转换为其他情况。
    2.若w是黑色，且w的子结点都是黑色，可从x和w上都去掉一层黑色，并把这层黑色加到p上，并把p设置成新的x，开始下次循环。
    3.若w的右子结点为黑，将w右旋，可变为情况4.
    4.若w的右子结点为红，将p左旋，可让root的左子树获得一个新结点。将新结点涂黑，

如果被删除的结点y是黑色，将其删除后（假设x在root的左子树上）以root的左子树上就减少了一个黑结点。我们要想办法在不改变其它子树上黑结点数目的前提下，将root左子树的黑结点数目增加1。
修复方法：
    1.若w为红(那么w的子结点必为黑)，通过将p左旋，可让x获得一个新的黑色兄弟结点w，从而转换为其他情况。
    2.若w为黑，且w子结点均为黑，可将w涂红（root右子树黑结点少一个），并将p涂黑(两边黑结点均多一个，root右子树黑结点相当于数目不变)。若p本为黑，则p为新x。开始下一轮循环。
    3.若w的右子结点为黑，可将w右旋，变为情况4.
    4.若w的右子结点为红，可将p左旋，让root左子树获得一个新的结点，右子树减少一个结点。将新结点涂黑，则root左子树增加一个黑结点；将w的右子结点(红色)涂黑，则右子树的黑结点数目不变；将w涂成原来的root的颜色。
 */
void rb_delete_fixup(RB_TREE *tree, RB_NODE *x)
{
    RB_NODE *w;
    while (x != tree->root && x->color == RB_BLACK) {
        if (x == x->parent->lchild) {
            w = x->parent->rchild;
            if (w->color == RB_RED) {
                puts("case 1");
                w->color = RB_BLACK;
                x->parent->color = RB_RED;
                rb_left_rotate(tree, x->parent);
                w = x->parent->rchild;
            }
            if (w->lchild->color == RB_BLACK && w->rchild->color == RB_BLACK) {
                puts("case 2");
                w->color = RB_RED;
                x = x->parent;
            } else {
                if (w->rchild->color == RB_BLACK) {
                    puts("case 3");
                    w->color = RB_RED;
                    w->lchild->color = RB_BLACK;
                    rb_right_rotate(tree, w);
                    w = x->parent->rchild;
                }
                puts("case 4");
                w->color = x->parent->color; //考虑范围内的root颜色不变
                w->rchild->color = RB_BLACK;
                x->parent->color = RB_BLACK;
                rb_left_rotate(tree, x->parent);
                x = tree->root; //问题解决，快速结束函数
            }
        } else {
            w = x->parent->lchild;
            if (w->color == RB_RED) {
                w->color = RB_BLACK;
                x->parent->color = RB_RED;
                rb_right_rotate(tree, x->parent);
                w = x->parent->lchild;
            }
            if (w->lchild->color == RB_BLACK && w->rchild->color == RB_BLACK) {
                w->color = RB_RED;
                x = x->parent;
            } else {
                if (w->lchild->color == RB_BLACK) {
                    w->color = RB_RED;
                    w->rchild->color = RB_BLACK;
                    rb_left_rotate(tree, w);
                    w = x->parent->lchild;
                }
                w->color = x->parent->color; //考虑范围内的root颜色不变
                w->lchild->color = RB_BLACK;
                x->parent->color = RB_BLACK;
                rb_right_rotate(tree, x->parent);
                x = tree->root; //问题解决，快速结束函数
            }
        }
    }
    x->color = RB_BLACK;
}
