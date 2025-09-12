class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
    
        // dp[i][j]: min sum of any falling path that ends at (i, j)
        int[][] dp = new int[n][n];

        // Base cases
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = dp[i-1][j] + matrix[i][j];
                if (j-1 >= 0) {
                    dp[i][j] = Math.min(dp[i][j], dp[i-1][j-1] + matrix[i][j]);
                }
                if (j+1 < n) {
                    dp[i][j] = Math.min(dp[i][j], dp[i-1][j+1] + matrix[i][j]);
                }
            }
        }

        int res = Integer.MAX_VALUE;
        for (int j = 0; j < n; j++) {
            res = Math.min(res, dp[n-1][j]);
        }
        return res;
    }
}