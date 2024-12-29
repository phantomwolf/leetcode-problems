class Solution {
    public boolean hasPath(int[][] maze, int[] start, int[] destination) {
        boolean[][] visited = new boolean[maze.length][maze[0].length];
        return dfs(maze, start, destination, visited);
    }

    private boolean dfs(int[][] maze, int[] start, int[] destination, boolean[][] visited) {
        // Termination condition
        if (start[0] == destination[0] && start[1] == destination[1]) {
            return true;
        }
        // Visit adjacent nodes
        int[][] diffs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int[] diff : diffs) {
            int x = start[0] + diff[0];
            int y = start[1] + diff[1];
            while (x >= 0 && x < maze.length && y >= 0 && y < maze[0].length && maze[x][y] != 1) {
                x += diff[0];
                y += diff[1];
            }
            x -= diff[0];
            y -= diff[1];
            // If already visited, skip
            if (visited[x][y]) {
                continue;
            }
            visited[x][y] = true;
            boolean ret = dfs(maze, new int[]{x, y}, destination, visited);
            if (ret) {
                return true;
            }
        }
        return false;
    }
}

