# 200. Number of Islands
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

Constraints:

* m == grid.length
* n == grid[i].length
* 1 <= m, n <= 300
* grid[i][j] is '0' or '1'.

## Solution 1: DFS
Iterate all coordinates of the grid. Each time we meet a '1', increase island number `count` and do DFS from this position.

While doing DFS, we mark visited positions as '2' in the grid[][]. This way we don't need a visited[][] matrix.

Time complexity: O(V*E) = O(mn)
Space complexity: O(1)

## Solution 2: Union find(overkill for this problem)

1. Create a union find structure for each position in the grid.
2. Iterate the grid, if two positions are both '1' and adjacent, run "union" operation on them.
3. The number of connected component minus the number of '0's is the result.
