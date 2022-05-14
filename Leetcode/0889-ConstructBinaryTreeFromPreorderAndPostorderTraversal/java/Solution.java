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
    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        return constructFromPrePost(preorder, 0, preorder.length - 1,
                                    postorder, 0, postorder.length - 1);
    }

    private TreeNode constructFromPrePost(int[] preorder, int preStart, int preEnd,
                                          int[] postorder, int postStart, int postEnd) {
        // base case
        if (preStart > preEnd) {
            // No nodes in this tree
            return null;
        } else if (preStart == preEnd) {
            // Only 1 node in this tree
            return new TreeNode(preorder[preStart]);
        }

        int count = 0;  // record the common integers which exist in both preSet and postSet
        Set<Integer> preSet = new HashSet<>();
        Set<Integer> postSet = new HashSet<>();
        int preIndex = preStart + 1;
        int postIndex = postStart;
        while (preIndex <= preEnd) {
            preSet.add(preorder[preIndex]);
            postSet.add(postorder[postIndex]);
            if (preorder[preIndex] == postorder[postIndex]) {
                count++;
            } else {
                if (preSet.contains(postorder[postIndex]))
                    count++;
                if (postSet.contains(preorder[preIndex]))
                    count++;
            }
            preIndex++;
            postIndex++;
            if (count == preSet.size()) {
                break;
            }
        }
        // Recursively build left and right subtrees
        TreeNode leftTree = constructFromPrePost(preorder, preStart + 1, preIndex - 1,
                                                 postorder, postStart, postIndex - 1);
        TreeNode rightTree = constructFromPrePost(preorder, preIndex, preEnd,
                                                  postorder, postIndex, postEnd - 1);
        TreeNode root = new TreeNode(preorder[preStart], leftTree, rightTree);
        return root;
    }
}
