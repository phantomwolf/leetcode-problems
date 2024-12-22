# 863. All Nodes Distance K in Binary Tree
We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
Output: [7,4,1]

Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.

Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.

Note:

1. The given tree is non-empty.
2. Each node in the tree has unique values 0 <= node.val <= 500.
3. The target node is a node in the tree.
4. 0 <= K <= 1000.

# Solution
This problem is a graph problem, however we're given a tree. The tree has no parent node, which means we can't access a node's parent conveniently. To solve this, we can first build a HashMap<Integer, TreeNode> which stores mapping from TreeNode.val to its parent TreeNode.

## Solution 1
After building the parent node mapping, do a BFS from the target and track the distances at the same time.

## Solution 2
The graph we're given is a tree, which means there's no circle in it. This means we can do DFS without having to worry that a node is visited in a detour instead of its shortest path.

