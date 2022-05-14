class RecursiveSolution {
    public int maxDepth(TreeNode root) {
        return maxDepth(root, 1);
    }

    // Recursively calculate the max depth of subtree
    private int maxDepth(TreeNode node, int depth) {
        if (node == null) {
            return 0;
        }
        int leftDepth = maxDepth(node.left, depth + 1);
        int rightDepth = maxDepth(node.right, depth + 1);
        depth = Math.max(depth, leftDepth);
        depth = Math.max(depth, rightDepth);
        return depth;
    }
}

public class Main {
    public static void main(String[] args) {
    }
}
