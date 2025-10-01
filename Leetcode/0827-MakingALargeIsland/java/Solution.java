class Solution {
    private static int[][] DIRS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    public int largestIsland(int[][] grid) {
        Map<Integer, Integer> islandSizes = new HashMap<>();
        int islandId = 10;

        // Calculate island sizes
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] != 1) {
                    continue;
                }
                islandSizes.put(islandId, 0);
                dfs(grid, i, j, islandId, islandSizes);
                islandId++;
            }
        }

        int largestIslandSize = 0;
        for (Map.Entry<Integer, Integer> entry : islandSizes.entrySet()) {
            largestIslandSize = Math.max(largestIslandSize, entry.getValue());
        }

        // Try to connect islands
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] != 0) {
                    continue;
                }
                // 4 directions
                Set<Integer> neighboringIslands = new HashSet<>();
                for (int[] dir : DIRS) {
                    int x = i + dir[0];
                    int y = j + dir[1];
                    if (x < 0 || x >= grid.length || y < 0 || y >= grid[0].length) {
                        // Out of boundary
                        continue;
                    }
                    if (grid[x][y] <= 1) {
                        continue;
                    }
                    neighboringIslands.add(grid[x][y]);
                }

                // After replacing 0 with 1, new island size is 1 + neighboringIslandSizes
                int totalSize = 1;
                for (int id : neighboringIslands) {
                    totalSize += islandSizes.get(id);
                }
                largestIslandSize = Math.max(largestIslandSize, totalSize);
            }
        }
        return largestIslandSize;
    }

    private void dfs(int[][] grid, int i, int j, int islandId, Map<Integer, Integer> islandSizes) {
        if (grid[i][j] != 1) {
            return;
        }
        // Mark as visited and record island id
        grid[i][j] = islandId;
        islandSizes.put(islandId, islandSizes.get(islandId) + 1);

        // Neighbors
        for (int[] dir : DIRS) {
            int x = i + dir[0];
            int y = j + dir[1];
            if (x < 0 || x >= grid.length || y < 0 || y >= grid[0].length) {
                // Out of boundary
                continue;
            }
            dfs(grid, x, y, islandId, islandSizes);
        }
    }
}