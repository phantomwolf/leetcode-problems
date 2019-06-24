class Main {
    public static void main(String[] args) {
        Integer nodes[] = {3,5,1,6,2,0,8,null,null,7,4};
        Tree tree = new Tree(nodes);
        distanceK(tree.root, 
    }

    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        List<Integer> result = new LinkedList<Integer>();
        Stack<TreeNode> path = new Stack<TreeNode>();
        
        TreeNode node = root;
        while (node.val != target.val) {
            path.push(node);
            if (target.val < node.val) {
                node = node.left;
            } else {
                node = node.right;
            }
        }
        path.push(node);
        
        while (K >= 0) {
            node = path.pop();
            result = bfs(node, K, result);
            K--;
        }
        return result;
    }

    public static List<Integer> bfs(TreeNode node, int distance, List<Integer> result) {
        if (distance == 0) {
            result.add(node.val);
            return result;
        }
        if (node.left != null) {
            bfs(node.left, distance - 1, result);
        }
        if (node.right != null) {
            bfs(node.left, distance - 1, result);
        }
        return result;
    }
}
