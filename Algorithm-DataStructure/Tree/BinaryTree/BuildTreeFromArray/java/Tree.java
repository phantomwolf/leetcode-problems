import java.util.*;


public class Tree {
    protected TreeNode root;

    public Tree(Integer[] nodes) {
        if (nodes.length == 0) {
            this.root = null;
            return;
        }
        // Root
        this.root = new TreeNode(nodes[0]);
        // Queue
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        System.out.println("root: " + this.root.val);

        TreeNode curr = this.root;
        TreeNode node;
        boolean left = true;
        for (int i=1; i < nodes.length; i++) {
            if (nodes[i] != null) {
                node = new TreeNode(nodes[i]);
            } else {
                node = null;
            }
            queue.add(node);
            if (left == true) {
                curr.left = node;
                left = false;
                System.out.println(" " + curr.val + ".left = " + ((node == null) ? node : node.val));
            } else {
                curr.right = node;
                left = true;
                System.out.println(" " + curr.val + ".right = " + ((node == null) ? node : node.val));
                curr = queue.remove();
            }
        }
    }

    public void print() {
        this.root.printSubtree();
    }
}
