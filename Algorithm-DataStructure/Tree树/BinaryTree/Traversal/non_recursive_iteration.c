#include <stdio.h>
#include <stdlib.h>


#define STACK_SIZE 1024

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void non_recursive_iterate1(struct TreeNode *t)
{
    // A makeshift stack
    int head = 0;
    struct TreeNode *stack[STACK_SIZE];

    stack[head++] = t;
    struct TreeNode *p = t->left;
    while (head != 0 || p != NULL) {
        if (p != NULL) {
            stack[head++] = p;
            p = p->left;
        } else {
            p = stack[--head];
            // Visit node
            printf("%d\n", p->val);
            // Add p->right to stack if any
            p = p->right;
        }
    }
}

void non_recursive_iterate2(struct TreeNode *t)
{
    // A makeshift stack
    int head = 0;
    struct TreeNode *stack[STACK_SIZE];

    struct TreeNode *p = t;
    while (head != 0 || p != NULL) {
        while (p != NULL) {
            stack[head++] = p;
            p = p->left;
        }
        if (head != 0) {
            p = stack[--head];
            printf("%d\n", p->val);
            p = p->right;
        }
    }
}


int main(int argc, char *argv[])
{
/*              5
 *      2               8
 *          3       7       9
 */
    struct TreeNode *nodes[6];
    for (int i = 0; i < 6; ++i) {
        nodes[i] = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        nodes[i]->left = nodes[i]->right = NULL;
    }

    nodes[0]->val = 5;
    nodes[0]->left = nodes[1];
    nodes[0]->right = nodes[2];
    nodes[1]->val = 2;
    nodes[2]->val = 8;

    nodes[1]->right = nodes[3];
    nodes[3]->val = 3;

    nodes[2]->left = nodes[4];
    nodes[2]->right = nodes[5];
    nodes[4]->val = 7;
    nodes[5]->val = 9;

    non_recursive_iterate2(nodes[0]);

    return 0;
}
