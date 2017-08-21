#include <iostream>
#include <stack>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        // preorder traversal
        stack<TreeNode*> stk;
        TreeNode *node = root;
        while (node != nullptr || !stk.empty()) {
            while (node != nullptr) {
                // access node here
                swap(node->left, node->right);

                stk.push(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            node = node->right;
        }
        return root;
    }
};


void print_tree(TreeNode *root)
{
    cout << root->val;
    if (root->left == nullptr && root->right == nullptr)
        return;

    cout << "(";
    if (root->left)
        print_tree(root->left);
    if (root->right) {
        cout << ",";
        print_tree(root->right);
    }
    cout << ")";
}


int main(int argc, char *argv[])
{
    Solution s;
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    print_tree(root);
    cout << endl;

    s.invertTree(root);

    print_tree(root);
    cout << endl;

    return 0;
}
