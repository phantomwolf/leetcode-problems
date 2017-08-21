#include <iostream>
#include <stack>

using namespace std;


typedef struct TreeNode TreeNode;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void postorder(TreeNode *root)
{
    if (root == nullptr)
        return;

    stack<TreeNode*> stk;
    TreeNode *node = root;
    do {
        while (node) {
            // push node's right child and then node to stack
            if (node->right)
                stk.push(node->right);
            stk.push(node);
            // set node as node's left child
            node = node->left;
        }

        node = stk.top();
        stk.pop();

        if (node->right && (!stk.empty() && stk.top() == node->right)) {
            // 第一次访问到该结点，且该结点有右孩子
            // 将右孩子出栈，结点再次压回栈内
            stk.pop();
            stk.push(node);
            node = node->right;
        } else {
            // 第二次访问到该结点，或者结点没有右孩子
            // 直接访问
            cout << node->val << endl;
            node = NULL;
        }
    } while (!stk.empty());
}


int main()
{
    TreeNode *root      = new TreeNode(1);
    root->left          = new TreeNode(2);
    root->right         = new TreeNode(3);
    root->left->left    = new TreeNode(4);
    root->left->right   = new TreeNode(5);
    root->right->left   = new TreeNode(6);
    root->right->right  = new TreeNode(7);
    postorder(root);

    return 0;
}
