class Solution {
    private static int[][] DIRS = new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    public void wallsAndGates(int[][] rooms) {
        int m = rooms.length;
        int n = rooms[0].length;
        // Queue stores coordinates (x, y)
        Queue<int[]> queue = new ArrayDeque<>();

        // Add all gates into queue
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (rooms[x][y] == 0) {
                    queue.add(new int[]{x, y});
                }
            }
        }

        //BFS
        int dist = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int[] coord = queue.remove();
                // Visit neighbors
                for (int[] dir : DIRS) {
                    int x = coord[0] + dir[0];
                    int y = coord[1] + dir[1];
                    if (x >= 0 && x < m && y >= 0 && y < n && rooms[x][y] == Integer.MAX_VALUE) {
                        // Important: set the distance here also marks (x, y) as visited.
                        rooms[x][y] = dist + 1;
                        queue.add(new int[]{x, y});
                    }
                }
            }
            dist++;
        }
    }
}
