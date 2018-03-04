#include <iostream>
#include <stack>
#include <unordered_map>
#include <limits>

using namespace std;

typedef struct TreeNode TreeNode;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


inline int max3(int a, int b, int c)
{
    if (a > b) {
        return (a > c) ? a : c;
    } else {
        return (b > c) ? b : c;
    }
}

// Do postorder traversal and
// calculate left & right maximum path meanwhile
int maximum_path(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    // key: 结点的指针
    // value: 左路径和右路径中最长的一个，加上结点本身。(若该值小于0，则此值为0)
    unordered_map<TreeNode*, int> map;
    stack<TreeNode*> st;
    TreeNode *node = root;
    int max = numeric_limits<int>::min();
    do {
        while (node != nullptr) {
            if (node->right != nullptr)
                st.push(node->right);
            st.push(node);
            node = node->left;      // go left
        }

        node = st.top();
        st.pop();

        if (node->right != nullptr &&
                (st.empty() == false && st.top() == node->right)) {
            // first time to visit node
            st.pop();               // pop its right child
            st.push(node);          // push node back to stack
            node = node->right;     // go right
        } else {
            // second time to visit node
            unordered_map<TreeNode*, int>::const_iterator iter;
            int left_max, right_max, node_max;
            left_max = (node->left == nullptr) ? 0 : map[node->left];
            right_max = (node->right == nullptr) ? 0 : map[node->right];
            if (max < left_max + right_max + node->val)
                max = left_max + right_max + node->val;
            left_max += node->val;
            right_max += node->val;
            node_max = max3(left_max, right_max, 0);
            map[node] = node_max;
            node = nullptr;
        }
    } while(st.empty() == false);
    map.clear();
    return max;
}



int main(int argc, char *argv[])
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(1);

    root->right = new TreeNode(10);
    root->right->right = new TreeNode(-25);
    root->right->right->left = new TreeNode(3);
    root->right->right->left = new TreeNode(4);


    cout << maximum_path(root) << endl;

    return 0;
}
