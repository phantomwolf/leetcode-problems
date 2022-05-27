/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
};
*/

class Solution {
    public Node lowestCommonAncestor(Node p, Node q) {
        Set<Node> visited = new HashSet<>();
        while (p != null) {
            visited.add(p);
            p = p.parent;
        }
        while (q != null) {
            if (visited.contains(q))
                return q;
            q = q.parent;
        }
        return null;
    }
}
