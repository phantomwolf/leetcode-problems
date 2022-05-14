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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return buildTree(inorder, 0, inorder.length - 1,
                         postorder, 0, postorder.length - 1);
    }

    private TreeNode buildTree(int[] inorder, int inStart, int inEnd,
                               int[] postorder, int postStart, int postEnd) {
        // base case
        if (inStart > inEnd) {
            return null;
        } else if (inStart == inEnd) {
            return new TreeNode(inorder[inStart]);
        }

        int rootVal = postorder[postEnd];
        int rootIndex = inStart;
        while (inorder[rootIndex] != rootVal) {
            rootIndex++;
        }
        int leftSize = rootIndex - inStart;
        TreeNode leftTree = buildTree(inorder, inStart, rootIndex - 1,
                                      postorder, postStart, postStart + leftSize - 1);
        TreeNode rightTree = buildTree(inorder, rootIndex + 1, inEnd,
                                       postorder, postStart + leftSize, postEnd - 1);
        TreeNode root = new TreeNode(rootVal, leftTree, rightTree);
        return root;
    }
}
