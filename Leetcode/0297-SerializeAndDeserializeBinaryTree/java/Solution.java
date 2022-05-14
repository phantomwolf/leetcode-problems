/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {
    // Encodes a tree to a single string.
    // Example 1: 1(2,3(4,5))
    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        serializeTree(root, sb);
        return sb.toString();
    }

    // Preorder traversal
    private void serializeTree(TreeNode root, StringBuilder sb) {
        // base case
        if (root == null)
            return;
        sb.append(root.val);
        if (root.left == null && root.right == null)
            return;
        sb.append("(");
        serializeTree(root.left, sb);
        sb.append(",");
        serializeTree(root.right, sb);
        sb.append(")");
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data.length() == 0)
            return null;
        // Find the root value
        int leftParenthesisIndex = 0;
        while (leftParenthesisIndex < data.length() && data.charAt(leftParenthesisIndex) != '(')
            leftParenthesisIndex++;
        int rootVal = Integer.parseInt(data.substring(0, leftParenthesisIndex));
        if (leftParenthesisIndex == data.length()) {
            // leaf node
            return new TreeNode(rootVal);
        }
        // Find the comma which divides left and right subtrees
        int parenthesisCount = 0;
        int commaIndex = leftParenthesisIndex + 1;
        while (commaIndex < data.length()) {
            if (data.charAt(commaIndex) == '(')
                parenthesisCount++;
            else if (data.charAt(commaIndex) == ')')
                parenthesisCount--;
            if (parenthesisCount == 0 && data.charAt(commaIndex) == ',')
                break;
            commaIndex++;
        }
        TreeNode leftTree = deserialize(data.substring(leftParenthesisIndex + 1, commaIndex));
        TreeNode rightTree = deserialize(data.substring(commaIndex + 1, data.length() - 1));
        TreeNode root = new TreeNode(rootVal, leftTree, rightTree);
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));
