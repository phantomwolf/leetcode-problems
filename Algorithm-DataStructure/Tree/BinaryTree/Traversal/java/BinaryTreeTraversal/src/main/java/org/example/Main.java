package org.example;

import java.lang.*;
import java.util.*;
import java.util.stream.Collectors;

class TreeNode {
    public int val;
    public TreeNode left, right;

    public TreeNode(int val) {
        this.val = val;
    }

    public TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class BinaryTreeTraversal {
    public List<TreeNode> preorderResults = new ArrayList<>();
    public List<TreeNode> inorderResults = new ArrayList<>();
    
    public List<TreeNode> postorderResults = new ArrayList<>();

    // iterative preorder and inorder traversal
    public void preorderInorderTraversal(TreeNode root) {
        Stack<TreeNode> stack = new Stack<>();
        TreeNode node = root;
        while (node != null || !stack.isEmpty()) {
            while (node != null) {
                // preorder location
                preorderResults.add(node);
                stack.push(node);
                node = node.left;
            }
            node = stack.pop();
            // inorder location
            inorderResults.add(node);
            node = node.right;
        }
    }

    public void postorderTraversal(TreeNode root) {
        Stack<TreeNode> stack = new Stack<>();
        TreeNode node = root;
        while (node != null || !stack.isEmpty()) {
            while (node != null) {
                if (node.right != null) {
                    stack.push(node.right);
                }
                stack.push(node);
                node = node.left;
            }
            node = stack.pop();
            if (node.right != null && !stack.isEmpty() && node.right == stack.peek()) {
                // This is the first time we meet the node. Pop its right child out
                stack.pop();
                // Push the node back to stack
                stack.push(node);
                // Go right
                node = node.right;
            } else {
                // Second time we meet the node. Both its left and right subtrees have been traversed.
                postorderResults.add(node);
                node = null;
            }
        }
    }
}

public class Main {
    public static void main(String[] args) {
        TreeNode root = createTree();
        BinaryTreeTraversal traversal = new BinaryTreeTraversal();
        traversal.preorderInorderTraversal(root);
        traversal.postorderTraversal(root);

        List<String> preorder = traversal.preorderResults.stream().map(x -> String.valueOf(x.val)).collect(Collectors.toList());
        List<String> inorder = traversal.inorderResults.stream().map(x -> String.valueOf(x.val)).collect(Collectors.toList());
        List<String> postorder = traversal.postorderResults.stream().map(x -> String.valueOf(x.val)).collect(Collectors.toList());

        System.out.printf("preorder: %s\n", String.join(", ", preorder));
        System.out.printf("inorder: %s\n", String.join(", ", inorder));
        System.out.printf("postorder: %s\n", String.join(", ", postorder));
    }

    // Create a binary tree(not binary search tree)
    /*
     *                  1
     *               /     \
     *             2        5
     *           /  \      /
     *          3   4     6
     *                  /
     *                 7
     *                  \
     *                    8
     */
    static TreeNode createTree() {
        TreeNode node3 = new TreeNode(3);
        TreeNode node4 = new TreeNode(4);
        TreeNode node2 = new TreeNode(2, node3, node4);
        TreeNode node8 = new TreeNode(8);
        TreeNode node7 = new TreeNode(7, null, node8);
        TreeNode node6 = new TreeNode(6, node7, null);
        TreeNode node5 = new TreeNode(5, node6, null);
        TreeNode node1 = new TreeNode(1, node2, node5);
        return node1;
    }
}