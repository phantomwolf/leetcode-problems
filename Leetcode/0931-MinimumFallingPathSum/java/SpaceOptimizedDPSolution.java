public class SpaceOptimizedDPSolution {
    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
    
        // dp[i][j]: min sum of any falling path that ends at (i, j)
        int[] dp = new int[n];
        int[] prevDp = new int[n];

        // Base cases
        for (int j = 0; j < n; j++) {
            dp[j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            // Swap prevDp and dp
            int[] tmp = prevDp;
            prevDp = dp;
            dp = tmp;

            for (int j = 0; j < n; j++) {
                dp[j] = prevDp[j] + matrix[i][j];
                if (j-1 >= 0) {
                    dp[j] = Math.min(dp[j], prevDp[j-1] + matrix[i][j]);
                }
                if (j+1 < n) {
                    dp[j] = Math.min(dp[j], prevDp[j+1] + matrix[i][j]);
                }
            }
        }

        int res = Integer.MAX_VALUE;
        for (int j = 0; j < n; j++) {
            res = Math.min(res, dp[j]);
        }
        return res;
    }
}
