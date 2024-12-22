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
    private void buildParentMap(TreeNode node, TreeNode parent, HashMap<Integer, TreeNode> map) {
        // Termination condition
        if (node == null) {
            return;
        }
        // Pre-order traversal
        map.put(node.val, parent);
        // Children
        buildParentMap(node.left, node, map);
        buildParentMap(node.right, node, map);
    }

    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        List<Integer> result = new ArrayList<>();
        HashMap<Integer, TreeNode> map = new HashMap<>();
        buildParentMap(root, null, map);
        // BFS
        Queue<Pair<TreeNode, Integer>> queue = new LinkedList<>();
        HashSet<Integer> visited = new HashSet<>();

        queue.add(new Pair(target, 0));
        visited.add(target.val);
        while (!queue.isEmpty()) {
            Pair<TreeNode, Integer> pair = queue.remove();
            TreeNode node = pair.getKey();
            int distance = pair.getValue();
            if (distance > k) {
                return result;
            }
            if (distance == k) {
                result.add(node.val);
            }
            // Neighbors: left, right, parent
            if (node.left != null && !visited.contains(node.left.val)) {
                queue.add(new Pair(node.left, distance + 1));
                visited.add(node.left.val);
            }
            if (node.right != null && !visited.contains(node.right.val)) {
                queue.add(new Pair(node.right, distance + 1));
                visited.add(node.right.val);
            }
            TreeNode parent = map.get(node.val);
            if (parent != null && !visited.contains(parent.val)) {
                queue.add(new Pair(parent, distance + 1));
                visited.add(parent.val);
            }
        }
        return result;
    }
}
