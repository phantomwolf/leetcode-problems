#include <algorithm>
#include <limits>
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
  int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    longestPathToLeaf(root, diameter);
    return diameter;
  }

 private:
  int longestPathToLeaf(TreeNode* node, int& diameter) {
    // Longest path from node to any leaf in its left subtree
    int left = (node->left == nullptr)
                   ? 0
                   : longestPathToLeaf(node->left, diameter) + 1;
    // Longest path from node to any leaf in its right subtree
    int right = (node->right == nullptr)
                    ? 0
                    : longestPathToLeaf(node->right, diameter) + 1;
    // Update result
    if (left + right > diameter) {
      diameter = left + right;
    }
    return std::max(left, right);
  }
};