public class TreeNode {
    public Integer val;
    public TreeNode left;
    public TreeNode right;

    public TreeNode(int x) {
        this.val = new Integer(x);
    }
    public TreeNode(Integer x) {
        this.val = x;
    }
    public static void print(TreeNode node) {
        if (node.left != null) {
            print(node.left);
        }
        System.out.println(node.val);
        if (node.right != null) {
            print(node.right);
        }
    }
    public void printSubtree() {
        TreeNode.print(this);
    }
}
