# 329. Longest Increasing Path in a Matrix
Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

**Example 1:**

![example1](./grid1.jpg)

Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].

**Example 2:**

![example2](./grid2.jpg)

Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

**Example 3:**

Input: matrix = [[1]]
Output: 1

Constraints:

* m == matrix.length
* n == matrix[i].length
* 1 <= m, n <= 200
* 0 <= matrix[i][j] <= 231 - 1

## Solution: top-down DP + memo
First, think of a recursive solution. Let's define `recursiveSolution(matrix, x, y)` to return the longest increasing path length starting from (x, y):

* Base case: if all neighbors of (x, y) are no greater than `matrix[x][y]`, there's nowhere to go from (x, y). Thus the longest increasing path length is 1, which is (x, y) itself.
* For neighbor (a, b), if `matrix[a][b] > matrix[x][y]`, `recursiveSolution(matrix, x, y)` could be `1 + recursiveSolution(matrix, a, b)`. This means a possible answer is: calculate the longest increasing path length starting from (a, b), then add (x, y) to that path.

If we invoke recursiveSolution for each (x, y) in the matrix, apparently many values will be repeatedly calculated. This indicates we can use dynamic programming: use a memo[][] to store the results and avoid repeated calculations.
