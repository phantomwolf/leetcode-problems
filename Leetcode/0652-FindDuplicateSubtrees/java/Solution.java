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
    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        Map<String, Integer> subtreeCount = new HashMap<>();
        List<TreeNode> result = new ArrayList<>();
        traverse(root, subtreeCount, result);
        return result;
    }

    // Postorder traverse the tree, serialize all subtrees at the same time and save them into a Map
    private String traverse(TreeNode node, Map<String, Integer> subtreeCount, List<TreeNode> result) {
        // base case
        if (node == null)
            return "";
        // Serialize node
        StringBuilder sb = new StringBuilder();
        sb.append(node.val);
        if (node.left != null || node.right != null) {
            // Serialize subtrees
            sb.append("(");
            sb.append(traverse(node.left, subtreeCount, result));
            sb.append(",");
            sb.append(traverse(node.right, subtreeCount, result));
            sb.append(")");
        }
        // Record the tree in map
        String s = sb.toString();
        subtreeCount.put(s, subtreeCount.getOrDefault(s, 0) + 1);
        // Find a duplicate for the first time
        if (subtreeCount.get(s) == 2) {
            result.add(node);
        }
        return s;
    }
}
