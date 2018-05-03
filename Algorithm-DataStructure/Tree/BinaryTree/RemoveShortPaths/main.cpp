#include <iostream>
#include <vector>
#include <stack>

using namespace std;


typedef struct Node Node;
struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

inline bool is_leaf(Node *node)
{
    return (node->left == nullptr) && (node->right == nullptr);
}

Node *remove_short_paths(Node *root, int k)
{
    if (root == nullptr)
        return nullptr;

    Node *node = root;
    stack<pair<Node*, int>> stk;
    int level = 1;
    do {
        while (node != nullptr) {
            if (node->right)
                stk.push({node->right, level + 1});
            stk.push({node, level});
            node = node->left;
            ++level;
        }
        node = stk.top().first;
        level = stk.top().second;
        stk.pop();
        if (node->right && !stk.empty() && node->right == stk.top().first) {
            // first time
            stk.pop();
            // push node back to stack
            stk.push({node, level});
            node = node->right;
            ++level;
        } else {
            // second time or node has no right child
            if (level < k && is_leaf(node)) {
                // remove node
                // Here stk.top() must be node's parent if stk is not empty
                if (stk.empty()) {
                    // we're deleting root
                    delete node;
                    return nullptr;
                }
                if (stk.top().first->left == node) {
                    stk.top().first->left = nullptr;
                } else {
                    stk.top().first->right = nullptr;
                }
                cout << "deleting child " << node->val << " of parent " << stk.top().first->val << endl;
                delete node;
            }
            node = nullptr;
        }
    } while (!stk.empty());
    return root;
}


void print_tree(Node *root)
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



int main()
{
    int k = 4;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(7);
    root->right = new Node(3);
    root->right->right = new Node(6);
    root->right->right->left = new Node(8);

    print_tree(root);
    cout << endl;

    root = remove_short_paths(root, k);

    if (root == nullptr) {
        cout << "Tree is completely deleted" << endl;
        return 0;
    }

    print_tree(root);
    cout << endl;


    return 0;
}
