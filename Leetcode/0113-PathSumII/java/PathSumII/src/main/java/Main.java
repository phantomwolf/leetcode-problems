import java.lang.*;
import java.util.*;

/**
 * Definition for a binary tree node.
 */
class TreeNode {
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

class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        if (root == null) {
            return new ArrayList<List<Integer>>();
        }
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        traverse(root, targetSum, 0, new Stack<Integer>(), result);
        return result;
    }

    // currSum: current sum of the path
    // path: current path
    // result: final result
    public void traverse(TreeNode node, int targetSum, int currSum, Stack<Integer> path, List<List<Integer>> result) {
        currSum += node.val;
        path.add(node.val);
        if (node.left == null && node.right == null) {
            // leaf
            if (currSum == targetSum) {
                result.add(new ArrayList<Integer>(path));
            }
        }
        if (node.left != null) {
            traverse(node.left, targetSum, currSum, path, result);
        }
        if (node.right != null) {
            traverse(node.right, targetSum, currSum, path, result);
        }
        path.pop();
    }
}

public class Main {
    public static void main(String[] args) {
        System.out.println("fool");
    }
}
