package MaximalSquare;

public class Solution {
    public int maximalSquare(char[][] matrix) {
        // Define dp[i][j] as the side length of an maximal square which ends at matrix[i][j]
        int[][] dp = new int[matrix.length][matrix[0].length];
        int maxSideLength = 0;
        // base case
        for (int i = 0; i < matrix.length; i++) {
            dp[i][0] = (matrix[i][0] == '1') ? 1 : 0;
            if (dp[i][0] == 1)
                maxSideLength = 1;
        }
        for (int j = 0; j < matrix[0].length; j++) {
            dp[0][j] = (matrix[0][j] == '1') ? 1 : 0;
            if (dp[0][j] == 1)
                maxSideLength = 1;
        }
        // Dynamic programming
        for (int i = 1; i < matrix.length; i++) {
            for (int j = 1; j < matrix[0].length; j++) {
                if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                    continue;
                }
                int minNeighborSideLength = Math.min(dp[i - 1][j], dp[i][j - 1]);
                minNeighborSideLength = Math.min(dp[i - 1][j - 1], minNeighborSideLength);
                dp[i][j] = minNeighborSideLength + 1;
                // Update overall max side length
                if (dp[i][j] > maxSideLength)
                    maxSideLength = dp[i][j];
            }
        }
        return maxSideLength * maxSideLength;
    }
}
