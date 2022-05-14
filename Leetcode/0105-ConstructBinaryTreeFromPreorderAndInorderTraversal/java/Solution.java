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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return buildTree(preorder, 0, preorder.length - 1,
                         inorder, 0, inorder.length - 1);
    }

    private TreeNode buildTree(int[] preorder, int preLeft, int preRight,
                               int[] inorder, int inLeft, int inRight) {
        // base case
        if (preLeft > preRight) {
            return null;
        } else if (preLeft == preRight) {
            return new TreeNode(preorder[preLeft]);
        }

        int rootVal = preorder[preLeft];
        int index = inLeft;
        while (inorder[index] != rootVal) {
            index++;
        }
        int leftSize = index - inLeft;  // size of the left subtree
        TreeNode leftTree = buildTree(preorder, preLeft + 1, preLeft + leftSize,
                                      inorder, inLeft, index - 1);
        TreeNode rightTree = buildTree(preorder, preLeft + leftSize + 1, preRight,
                                       inorder, index + 1, inRight);
        TreeNode root = new TreeNode(rootVal, leftTree, rightTree);
        return root;
    }
}
