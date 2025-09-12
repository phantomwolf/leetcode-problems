/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val,Node _left,Node _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

public class Solution {
    // To make it easy, use member variables to record dummy head and tail.
    Node dummy = new Node();
    Node tail = dummy;

    public Node treeToDoublyList(Node root) {
        // Corner case
        if (root == null) {
            return null;
        }

        inorder(root);
        // Form a circle
        tail.right = dummy.right;
        dummy.right.left = tail;
        return dummy.right;
    }

    private void inorder(Node node) {
        if (node == null) {
            return;
        }
        // Left subtree
        inorder(node.left);

        tail.right = node;
        node.left = tail;
        tail = node;

        // Right subtree
        inorder(node.right);
    }
}