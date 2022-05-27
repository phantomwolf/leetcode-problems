# 222. Count Complete Tree Nodes
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

## Example 1

```
          1
      /      \
    2         3
 /     \    /
4       5  6

Input: root = [1,2,3,4,5,6]
Output: 6
```

## Example 2

```
Input: root = []
Output: 0
```

## Example 3

```
Input: root = [1]
Output: 1
```

## Constraints:
- The number of nodes in the tree is in the range [0, 5 * 104].
- 0 <= Node.val <= 5 * 104
- The tree is guaranteed to be complete.

## Solution
### Prerequisites
A **perfect binary tree** is a type of binary tree in which every internal node has exactly two child nodes and all the leaf nodes are at the same level. Its number of nodes can be calculated from its height h with the following formula:

    number_of_nodes = 2^h - 1

Note: a binary tree with a single node has a height of 1.

### Explanation
Although the binary tree in this problem is a complete binary tree, instead of a perfect binary tree, we can see some of its subtrees are perfect binary trees. For example, the subtree with a root value of 2:

```
    2
 /     \
4       5
```

If we find a subtree which is a perfect binary tree, we can quickly calculate its number of nodes by its height. For such subtrees, we don't have to traverse all its nodes.

So how do we know if a tree is a perfect binary tree? We can calculate the length of the leftmost and rightmost paths. If they equal with each other, it's a perfect binary tree.
