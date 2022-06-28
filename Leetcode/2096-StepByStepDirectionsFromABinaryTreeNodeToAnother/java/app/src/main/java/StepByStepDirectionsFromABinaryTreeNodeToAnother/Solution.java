package StepByStepDirectionsFromABinaryTreeNodeToAnother;

import java.util.LinkedList;

public class Solution {
    private LinkedList<Character> startPath = new LinkedList<>();
    private LinkedList<Character> destPath = new LinkedList<>();

    public String getDirections(TreeNode root, int startValue, int destValue) {
        postorder(root, startValue, destValue);
        // Merge 2 paths
        StringBuilder sb = new StringBuilder();
        for (char c : startPath) {
            sb.append(c);
        }
        for (char c : destPath) {
            sb.append(c);
        }
        return sb.toString();
    }

    private byte postorder(TreeNode node, int startValue, int destValue) {
        byte ret = 0;
        if (node.left != null) {
            byte leftRet = postorder(node.left, startValue, destValue);
            if (leftRet == 0b01) {
                startPath.addLast('U');
            } else if (leftRet == 0b10) {
                destPath.addFirst('L');
            }
            ret |= leftRet;
        }
        if (node.right != null) {
            byte rightRet = postorder(node.right, startValue, destValue);
            if (rightRet == 0b01) {
                startPath.addLast('U');
            } else if (rightRet == 0b10) {
                destPath.addFirst('R');
            }
            ret |= rightRet;
        }
        if (node.val == startValue) {
            ret |= 0b01;
        } else if (node.val == destValue) {
            ret |= 0b10;
        }
        if (ret == 0b11) {
            // Lowest Common Ancestor
            return 0;
        }
        return ret;
    }
}