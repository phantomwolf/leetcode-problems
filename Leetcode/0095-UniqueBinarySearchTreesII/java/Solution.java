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
    public List<TreeNode> generateTrees(int n) {
        return generateTrees(1, n);
    }

    // Generate trees with values in [lo, hi]. Postorder traversal
    private List<TreeNode> generateTrees(int lo, int hi) {
        List<TreeNode> trees = new ArrayList<>();
        if (lo > hi) {
            trees.add(null);
            return trees;
        }
        for (int r = lo; r <= hi; r++) {
            List<TreeNode> leftTrees = generateTrees(lo, r - 1);
            List<TreeNode> rightTrees = generateTrees(r + 1, hi);
            for (TreeNode left : leftTrees) {
                for (TreeNode right : rightTrees) {
                    TreeNode root = new TreeNode(r, left, right);
                    trees.add(root);
                }
            }
        }
        return trees;
    }
}
