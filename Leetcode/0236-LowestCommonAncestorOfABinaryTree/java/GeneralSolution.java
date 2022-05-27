/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private TreeNode lca;

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        find(root, p, q);
        return lca;
    }

    private boolean find(TreeNode root, TreeNode p, TreeNode q) {
        // Already found lca
        if (lca != null)
            return false;
        if (root == null)
            return false;
        int found = 0;
        if (find(root.left, p, q))
            found++;
        if (find(root.right, p, q))
            found++;
        if (root == p || root == q) {
            found++;
        }
        switch (found) {
            case 2:
                lca = root;
                return true;
            case 1:
                return true;
            default:
                return false;
        }
    }
}
