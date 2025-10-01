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
    int maxSum = Integer.MIN_VALUE;

    public int maxPathSum(TreeNode root) {
        oneSideMax(root);
        return maxSum;
    }

    // The path sum that ends at node
    private int oneSideMax(TreeNode node) {
        // Base case
        if (node == null) {
            return 0;
        }

        int localSum = node.val;
        int leftSum = oneSideMax(node.left);
        if (leftSum > 0) {
            localSum += leftSum;
        }
        int rightSum = oneSideMax(node.right);
        if (rightSum > 0) {
            localSum += rightSum;
        }
    
        // Update result
        maxSum = Math.max(maxSum, localSum);

        return node.val + Math.max(Math.max(leftSum, rightSum), 0);
    }
}