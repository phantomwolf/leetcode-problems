class Solution {
    private static int[][] DIRS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    public int longestIncreasingPath(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[][] memo = new int[m][n];

        int longest = Integer.MIN_VALUE;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                longest = Math.max(longest, dp(matrix, i, j, memo));
            }
        }
        return longest;
    }

    private int dp(int[][] matrix, int x, int y, int[][] memo) {
        // Query memo
        if (memo[x][y] != 0) {
            return memo[x][y];
        }

        int longest = 1;
        for (int[] dir : DIRS) {
            int a = x + dir[0];
            int b = y + dir[1];
            
            if (a < 0 || a >= matrix.length || b < 0 || b >= matrix[0].length) {
                // (a, b) out of boundary
                continue;
            }
            if (matrix[a][b] <= matrix[x][y]) {
                continue;
            }

            int cand = 1 + dp(matrix, a, b, memo);
            longest = Math.max(longest, cand);
        }
        
        // Update memo
        memo[x][y] = longest;
        return longest;
    }
}