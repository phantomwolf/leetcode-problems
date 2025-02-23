import java.lang.*;
import java.util.*;

/**
 * Definition for a binary tree node.
 */
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class ExtraSpaceSolution {
    public void flatten(TreeNode root) {
        List<TreeNode> path = new ArrayList<>();
        traverse(root, path);
        for (int i = 0; i < path.size(); i++) {
            TreeNode next = ((i + 1) < path.size()) ? path.get(i + 1) : null;
            TreeNode node = path.get(i);
            node.left = null;
            node.right = next;
        }
    }

    private void traverse(TreeNode node, List<TreeNode> path) {
        if (node == null) {
            return;
        }
        path.add(node);
        traverse(node.left, path);
        traverse(node.right, path);
    }
}

// DFS with an instance variable
class InPlaceSolution {
    TreeNode prev = null;

    public void flatten(TreeNode root) {
        if (root == null) {
            return;
        }
        TreeNode left = root.left, right = root.right;
        if (prev != null) {
            prev.left = null;
            prev.right = root;
        }
        prev = root;
        flatten(left);
        flatten(right);
    }
}

// First flatten left and right subtrees recursively, then connect them with root
class SubtreeSolution {
    public void flatten(TreeNode root) {
        // base case
        if (root == null) return;
        // flatten left and right subtree
        flatten(root.left);
        flatten(root.right);
        /* postorder traversal location */
        // Use variables to record left and right subtree
        TreeNode left = root.left, right = root.right;
        // Connect root, left subtree and right subtree
        root.left = null;
        root.right = left;
        TreeNode node = root;
        while (node.right != null) {
            node = node.right;
        }
        node.right = right;
    }
}

public class Main {
    public static void main(String[] args) {
    }
}
