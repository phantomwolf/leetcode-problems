#include "bst.h"

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>


/* 方法1：每次都从root出发向下前进，只打印一个指定的层 */

/* Print given level */
void print_given_level(Node *node, int level)
{
    if (node == NULL)
        return;
    if (level == 1) {
        printf("%d, ", node->data);
    } else {
        print_given_level(node->left, level - 1);
        print_given_level(node->right, level - 1);
    }
}

/* Driver function */
void print_level_order(Tree *tree)
{
    printf("Level order traversal(Breadth first traversal): \n");
    for (int i = 1; i <= 4; ++i) {
        print_given_level(tree->root, i);
        puts("");
    }
    puts("");
}


/* 方法2：使用队列 */
void bfs_with_queue(Tree *tree)
{
    if (tree->root == NULL)
        return;
    printf("bfs with queue:\n");

    GQueue *queue = g_queue_new();
    g_queue_push_tail(queue, tree->root);
    while (!g_queue_is_empty(queue)) {
        Node *node = (Node *)g_queue_pop_head(queue);
        printf("%d, ", node->data);
        if (node->left != NULL)
            g_queue_push_tail(queue, node->left);
        if (node->right != NULL)
            g_queue_push_tail(queue, node->right);
    }
    g_queue_free(queue);
    puts("");
}

int main()
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

    print_level_order(tree);

    bfs_with_queue(tree);


    return 0;

}
