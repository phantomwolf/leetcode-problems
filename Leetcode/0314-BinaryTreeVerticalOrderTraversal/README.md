# 314. Binary Tree Vertical Order Traversal
Given the root of a binary tree, return the vertical order traversal of its nodes' values. (i.e., from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Example 1:

![example1](image1.png)

Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]

Example 2:

![example2](image2.png)

Input: root = [3,9,8,4,0,1,7]
Output: [[4],[9],[3,0,1],[8],[7]]

Example 3:

![example3](image3.png)

Input: root = [1,2,3,4,10,9,11,null,5,null,null,null,null,null,null,null,6]
Output: [[4],[2,5],[1,10,9,6],[3],[11]]

Constraints:

* The number of nodes in the tree is in the range [0, 100].
* -100 <= Node.val <= 100

## Solution 1: BFS
We can do BFS and track node's coordinates.

* The coordinate of root is (0, 0)
* If a node's coordinate is (x, y), its left child is (x-1, y+1) and right child is (x+1, y+1)

During the traversal, we store nodes with the same x coordinate into a list, and this list will be the vertical order of nodes in the same column(because in BFS, we visit nodes from top to bottom so they're already sorted by their y coordinate).

Time complexity: O(N). Space complexity: O(N). N is the number of nodes.

## Solution 2: DFS
We can do DFS and track node's coordinates.

The difference from BFS is, nodes with the same x coordinate are NOT sorted by their y coordinates. So for each value of x, we need to sort the list.

Time complexity: O(W * HlogH), W is tree's width and H is height. Space complexity: O(N). 
