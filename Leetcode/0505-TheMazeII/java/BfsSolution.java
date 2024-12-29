class Solution {
    public int shortestDistance(int[][] maze, int[] start, int[] destination) {
        int[][] distance = new int[maze.length][maze[0].length];
        for (int[] arr : distance) {
            Arrays.fill(arr, Integer.MAX_VALUE);
        }
        distance[start[0]][start[1]] = 0;
        Queue<int[]> queue = new LinkedList<>();
        queue.add(start);
        int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!queue.isEmpty()) {
            int[] pos = queue.remove();
            // Go 4 directions
            for (int[] dir : dirs) {
                int x = pos[0] + dir[0];
                int y = pos[1] + dir[1];
                int weight = 1;
                while (x >= 0 && x < maze.length && y >= 0 && y < maze[0].length && maze[x][y] != 1) {
                    x += dir[0];
                    y += dir[1];
                    weight++;
                }
                x -= dir[0];
                y -= dir[1];
                weight--;
                if (distance[x][y] > distance[pos[0]][pos[1]] + weight) {
                    distance[x][y] = distance[pos[0]][pos[1]] + weight;
                    queue.add(new int[]{x, y});
                }
            }
        }
        return distance[destination[0]][destination[1]] == Integer.MAX_VALUE ? -1 : distance[destination[0]][destination[1]];
    }
}
