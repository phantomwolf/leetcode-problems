/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int kthSmallest(struct TreeNode *root, int k)
{
    int stack[64];      // Stack size depends on the height of the tree
    int top = 0;

    struct TreeNode *node = root;
    while (top != 0 || node != NULL) {
        while (node != NULL) {
            stack[top++] = node;
            node = node->left;
        }
        if (top != 0) {
            node = stack[--top];
            if (--k == 0) {
                return node->val;
            }
            node = node->right;
        }
    }

    return -1;
}
