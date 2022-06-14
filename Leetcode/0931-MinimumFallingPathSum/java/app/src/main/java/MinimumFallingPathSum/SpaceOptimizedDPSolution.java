package MinimumFallingPathSum;

public class SpaceOptimizedDPSolution {
    public int minFallingPathSum(int[][] matrix) {
        int[] dp = new int[matrix[0].length];
        // base case
        for (int j = 0; j < matrix[0].length; j++) {
            dp[j] = matrix[0][j];
        }
        for (int i = 1; i < matrix.length; i++) {
            int left = Integer.MAX_VALUE;
            for (int j = 0; j < matrix[0].length; j++) {
                int tmp = dp[j];
                int right = (j + 1 < matrix[0].length) ? dp[j + 1] : Integer.MAX_VALUE;
                dp[j] = minOfThree(left, dp[j], right) + matrix[i][j];
                left = tmp;
            }
        }
        // Find the minimum value
        int minSum = Integer.MAX_VALUE;
        for (int j = 0; j < dp.length; j++) {
            if (dp[j] < minSum)
                minSum = dp[j];
        }
        return minSum;
    }

    private int minOfThree(int a, int b, int c) {
        int min = (a < b) ? a : b;
        return (min < c) ? min : c;
    }
}
