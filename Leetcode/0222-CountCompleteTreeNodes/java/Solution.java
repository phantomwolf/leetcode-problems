/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int countNodes(TreeNode root) {
        // base case
        if (root == null)
            return 0;
        // Check the height of leftmost and rightmost paths. If they're the same, this subtree is a perfect binary tree
        int leftHeight = 0;
        for (TreeNode node = root; node != null; node = node.left) {
            leftHeight++;
        }
        int rightHeight = 0;
        for (TreeNode node = root; node != null; node = node.right) {
            rightHeight++;
        }
        if (leftHeight == rightHeight) {
            // Perfect binary tree
            return (int) Math.pow(2, leftHeight) - 1;
        }
        return countNodes(root.left) + countNodes(root.right) + 1;
    }
}
