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
    private HashMap<Integer, TreeNode> parentMap = new HashMap<>();
    private HashSet<Integer> visited = new HashSet<>();
    private List<Integer> result = new ArrayList<>();

    private void buildParentMap(TreeNode node, TreeNode parent) {
        // Termination condition
        if (node == null) {
            return;
        }
        // Pre-order traversal
        parentMap.put(node.val, parent);
        // Children
        buildParentMap(node.left, node);
        buildParentMap(node.right, node);
    }

    private void dfs(TreeNode node, int distance, int k) {
        if (node == null || visited.contains(node.val)) {
            // null or already visited
            return;
        }
        visited.add(node.val);
        if (distance == k) {
            result.add(node.val);
        }
        // Neighbors
        dfs(node.left, distance + 1, k);
        dfs(node.right, distance + 1, k);
        TreeNode parent = parentMap.get(node.val);
        dfs(parent, distance + 1, k);
    }

    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        buildParentMap(root, null);
        dfs(target, 0, k);
        return result;
    }
}

