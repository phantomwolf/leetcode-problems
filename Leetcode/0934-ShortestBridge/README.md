# 934. Shortest Bridge
You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.

Example 1:

    Input: grid = [[0,1],[1,0]]
    Output: 1

Example 2:

    Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
    Output: 2

Example 3:

    Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
    Output: 1

Constraints:

* n == grid.length == grid[i].length
* 2 <= n <= 100
* grid[i][j] is either 0 or 1.
* There are exactly two islands in grid.

# Solution
The grid can be seen as a graph represented by an adjacent matrix. Each cell is a vertex and has 4 neighbors(unless it's on the border).

## DFS + BFS
The idea is to do BFS from the cells of one island until any cell of the other island is reached.

First, scan the grid until we find the first "1". Starting from this "1", do DFS and change all the "1" we met to "2", so that we can distinguish the two islands. Add all cells of this island to a queue for BFS later.

Do BFS from the borders of the island above. For each cell we meet:

- If it's 0, we've met an unvisited cell. Add it to queue and change its value to `previous_cell_value + 1`
- If it's 1, we've reached the other island. Calculate the shortest bridge length according to the value of the previous cell.
- If it's any value other than 0 or 1, it means the cell is already visited. Just ignore it.
