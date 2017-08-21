#include <iostream>
#include <vector>
#include <stack>

using namespace std;


typedef struct TreeNode TreeNode;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


TreeNode *build_tree_from_preorder(const vector<int> &pre)
{
    if (pre.size() == 0)
        return nullptr;
    // create root node
    TreeNode *root = new TreeNode(pre[0]);

    stack<TreeNode*> stk;
    stk.push(root);
    for (size_t i = 1; i < pre.size(); ++i) {
        TreeNode *next = new TreeNode(pre[i]);
        TreeNode *last_pop = nullptr;
        while (!stk.empty() && stk.top()->val < next->val) {
            last_pop = stk.top();
            stk.pop();
        }
        if (last_pop != nullptr) {
            last_pop->right = next;
            cout << last_pop->val << " right child is " << next->val << endl;
        } else if (!stk.empty()) {
            stk.top()->left = next;
            cout << stk.top()->val << " left child is " << next->val << endl;
        }
        stk.push(next);
    }

    return root;
}


void print_tree(TreeNode *root)
{
    cout << root->val;
    if (root->left == nullptr && root->right == nullptr)
        return;
    cout << "(";
    if (root->left != nullptr)
        print_tree(root->left);
    if (root->right != nullptr) {
        cout << ", ";
        print_tree(root->right);
    }
    cout << ")";
}


int main(int argc, char *argv[])
{
    vector<int> pre{10, 5, 1, 7, 40, 50};
    TreeNode *root = build_tree_from_preorder(pre);
    print_tree(root);
    cout << endl;

    return 0;
}
