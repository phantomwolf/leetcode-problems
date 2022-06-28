package ShortestBridge;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

public class GraphSolution {
    public int shortestBridge(int[][] grid) {
        Queue<Pair> q = new ArrayDeque<>();
        // Find the first cell of an island and paint the island
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    paintIsland(grid, i, j, 2, q);
                    //System.out.println(q);
                    return bfs(grid, q);
                }
            }
        }
        return -1;
    }

    // DFS traverse the graph and change their values to color
    private void paintIsland(int[][] grid, int i, int j, int color, Queue<Pair> q) {
        // Paint cell. This also indicates it's visited
        grid[i][j] = color;
        for (Pair p : neighbors(grid, i, j)) {
            if (grid[p.i][p.j] == 1) {
                // Paint its neighbors only when they're not painted and part of the island
                paintIsland(grid, p.i, p.j, color, q);
            } else if (grid[p.i][p.j] == 0) {
                // If one of its neighbors is 0, it's the border of the island
                grid[p.i][p.j] = color + 1;
                q.add(new Pair(p.i, p.j));
            }
        }
    }

    private List<Pair> neighbors(int[][] grid, int i, int j) {
        int[][] directions = {
                {-1, 0},    // up
                {1, 0},     // down
                {0, -1},    // left
                {0, 1},     // right
        };
        List<Pair> result = new ArrayList<>(4);
        for (int[] d : directions) {
            int m = i + d[0];
            int n = j + d[1];
            if (m < 0 || n < 0 || m >= grid.length || n >= grid[0].length) {
                // out of range
                continue;
            }
            result.add(new Pair(m, n));
        }
        return result;
    }

    private int bfs(int[][] grid, Queue<Pair> q) {
        while (!q.isEmpty()) {
            Pair p = q.remove();
            for (Pair n : neighbors(grid, p.i, p.j)) {
                if (grid[n.i][n.j] == 1) {
                    // Reached the other island
                    return grid[p.i][p.j] - 2;
                }
                if (grid[n.i][n.j] == 0) {
                    grid[n.i][n.j] = grid[p.i][p.j] + 1;
                    q.add(new Pair(n.i, n.j));
                }
            }
        }
        return -1;
    }
}
