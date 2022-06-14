package com.snowwolf;

public class SpaceOptimizedDPSolution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if (obstacleGrid[0][0] == 1)
            return 0;
        int[] dp = new int[obstacleGrid[0].length];
        // base case
        dp[0] = 1;
        for (int j = 1; j < dp.length; j++) {
            dp[j] = (obstacleGrid[0][j] == 1) ? 0 : dp[j - 1];
        }
        for (int i = 1; i < obstacleGrid.length; i++) {
            for (int j = 0; j < obstacleGrid[0].length; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                    continue;
                }
                int prev = (j - 1 >= 0) ? dp[j - 1] : 0;
                dp[j] = prev + dp[j];
            }
        }
        return dp[dp.length - 1];
    }
}