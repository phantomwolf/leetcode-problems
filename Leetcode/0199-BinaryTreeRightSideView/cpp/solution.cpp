#include <utility>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  vector<int> rightSideView(TreeNode* root) {
    if (root == nullptr) {
      return {};
    }
    // index: y, value: pair (x, val)
    vector<pair<int, int>> view;
    dfs(root, 0, 0, view);

    vector<int> result;
    for (auto p : view) {
      result.push_back(p.second);
    }
    return result;
  }

  void dfs(TreeNode* node, int x, int y, vector<pair<int, int>>& view) {
    if (node == nullptr) {
      return;
    }
    if (y == view.size()) {
      view.push_back({x, node->val});
    }
    // Visit subtrees
    dfs(node->right, x + 1, y + 1, view);
    dfs(node->left, x - 1, y + 1, view);
  }
};
