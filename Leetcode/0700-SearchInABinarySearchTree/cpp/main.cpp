#include <iostream>
#include <stack>
using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode *node = root;
        while (node != NULL ) {
            if (val == node->val)
                return node;
            if (val < node->val)
                node = node->left;
            else
                node = node->right;
        }
        return NULL;
    }
};


int main(int argc, char *argv[]) {
    return 0;
}
