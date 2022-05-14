package com.example;

import java.lang.*;
import java.util.*;

// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class DFSSolution {
    public Node connect(Node root) {
        if (root == null) {
            return null;
        }
        traverse(root.left, root.right);
        return root;
    }

    // DFS
    private void traverse(Node node1, Node node2) {
        if (node1 == null || node2 == null) {
            return;
        }
        // Connect node1 and node2
        node1.next = node2;
        // Connect their children
        traverse(node1.left, node1.right);
        traverse(node2.left, node2.right);
        // Connect the gap between them
        traverse(node1.right, node2.left);
    }
}

// BFS
class LevelOrderTraversalSolution {
    public Node connect(Node root) {
        if (root == null) {
            return null;
        }
        Queue<Node> queue = new LinkedList<Node>();
        queue.add(root);
        while (!queue.isEmpty()) {
            Node prev = null;
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                Node node = queue.remove();
                if (prev != null) {
                    prev.next = node;
                }
                prev = node;
                // add children
                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
            }
            prev.next = null;
        }
        return root;
    }
}

public class Main {

}
