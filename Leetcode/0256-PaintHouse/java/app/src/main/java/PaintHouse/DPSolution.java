package PaintHouse;

public class DPSolution {
    public int minCost(int[][] costs) {
        // Define dp[i][j] as the minimum cost to paint i houses, and house i is painted as color j
        int[][] dp = new int[costs.length][costs[0].length];
        for (int j = 0; j < costs[0].length; j++) {
            dp[0][j] = costs[0][j];
        }
        // Dynamic programming
        for (int i = 1; i < costs.length; i++) {
            for (int j = 0; j < costs[0].length; j++) {
                dp[i][j] = Math.min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + costs[i][j];
            }
        }
        // Find minimum cost
        int minimumCost = Integer.MAX_VALUE;
        for (int j = 0; j < costs[0].length; j++) {
            if (dp[dp.length - 1][j] < minimumCost) {
                minimumCost = dp[dp.length - 1][j];
            }
        }
        return minimumCost;
    }
}
