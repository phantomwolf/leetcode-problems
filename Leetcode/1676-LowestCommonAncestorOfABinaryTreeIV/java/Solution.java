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

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode[] nodes) {
        Set<TreeNode> set = new HashSet<>(Arrays.asList(nodes));
        find(root, set);
        return lca;
    }

    private int find(TreeNode root, Set<TreeNode> set) {
        if (lca != null)
            return -1;
        int count = 0;
        if (root == null)
            return 0;
        if (set.contains(root))
            count++;
        count += find(root.left, set);
        count += find(root.right, set);
        if (count == set.size() && lca == null)
            lca = root;
        return count;
    }
}
