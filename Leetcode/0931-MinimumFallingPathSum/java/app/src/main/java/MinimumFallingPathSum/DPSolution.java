package MinimumFallingPathSum;

public class DPSolution {
    public int minFallingPathSum(int[][] matrix) {
        int[][] dp = new int[matrix.length][matrix[0].length];
        // base case
        for (int j = 0; j < matrix[0].length; j++) {
            dp[0][j] = matrix[0][j];
        }
        for (int i = 1; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                int l = (j -1 >= 0) ? dp[i - 1][j - 1] : Integer.MAX_VALUE;
                int m = dp[i - 1][j];
                int r = (j + 1 < matrix[0].length) ? dp[i - 1][j + 1] : Integer.MAX_VALUE;
                dp[i][j] = minOfThree(l, m, r) + matrix[i][j];
            }
        }
        // Find the minimum value
        int minSum = Integer.MAX_VALUE;
        for (int j = 0; j < dp[0].length; j++) {
            if (dp[dp.length - 1][j] < minSum)
                minSum = dp[dp.length - 1][j];
        }
        return minSum;
    }

    private int minOfThree(int a, int b, int c) {
        int min = (a < b) ? a : b;
        return (min < c) ? min : c;
    }
}
