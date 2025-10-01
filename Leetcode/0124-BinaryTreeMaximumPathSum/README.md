# 124. Binary Tree Maximum Path Sum
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

Example 1:

![example1](./exx1.jpg)

Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
Example 2:

![example2](./exx2.jpg)

Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.

Constraints:

* The number of nodes in the tree is in the range [1, 3 * 104].
* -1000 <= Node.val <= 1000

## Solution: post-order DFS
This is a typical problem about "path in a tree".

A path is a sequence of nodes, starting from node A, to node B. A and B could be in the same subtree(e.g. A is B's ancestor), or they could be in different subtrees of a common ancestor.

To solve this kind of problem, we usually need a recursive helper function `oneSideMax`, which calculates the result of one side of a subtree. In this problem, define `oneSideMax(node)` as the max path sum of a path that ends at `node`. For node `root`, a possible value of the max sum may be `pathSum = root.val + oneSideMax(root.left) + oneSideMax(root.right)`. However, things can be more complicated than that. If `oneSideMax(root.left) < 0`, we can get a larger sum by discarding `oneSideMax(root.left)`.

