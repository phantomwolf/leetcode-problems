/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Pair<X, Y> {
    public X x;
    public Y y;
        
    public Pair(X x, Y y) {
        this.x = x;
        this.y = y;
    }
}

class Solution {
    protected Map<TreeNode, TreeNode> parentMap;

    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        this.parentMap = new HashMap<TreeNode, TreeNode>();
        this.dfs(root, null);
        // Perform bfs
        List<Integer> result = new ArrayList<Integer>();
        Set<TreeNode> seen = new HashSet<TreeNode>();
        Queue<Pair<TreeNode, Integer>> queue = new ArrayDeque<Pair<TreeNode, Integer>>();
        queue.add(new Pair(target, 0));
        seen.add(target);
        while (!queue.isEmpty()) {
            Pair<TreeNode, Integer> pair = queue.remove();
            if (pair.y == K) {
                result.add(new Integer(pair.x.val));
            }
            if (pair.y < K) {
                if (pair.x.left != null && !seen.contains(pair.x.left)) {
                    queue.add(new Pair(pair.x.left, pair.y+1));
                    seen.add(pair.x.left);
                }
                if (pair.x.right != null && !seen.contains(pair.x.right)) {
                    queue.add(new Pair(pair.x.right, pair.y+1));
                    seen.add(pair.x.right);
                }
                TreeNode parent = this.parentMap.get(pair.x);
                if (parent != null && !seen.contains(parent)) {
                    queue.add(new Pair(parent, pair.y+1));
                    seen.add(parent);
                }
            }
        }
        return result;
    }

    public void dfs(TreeNode node, TreeNode parent) {
        this.parentMap.put(node, parent);
        if (node.left != null) {
            this.dfs(node.left, node);
        }
        if (node.right != null) {
            this.dfs(node.right, node);
        }
    }
}
