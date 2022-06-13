package MinimumFallingPathSum;

public class SpaceOptimizedDPSolution {
    public int minFallingPathSum(int[][] matrix) {
        int[] prevDP = new int[matrix[0].length];
        int[] currDP = new int[matrix[0].length];
        // base case
        for (int j = 0; j < matrix[0].length; j++) {
            currDP[j] = matrix[0][j];
        }
        for (int i = 1; i < matrix.length; i++) {
            // swap prevDP and currDP
            int[] tmp = prevDP;
            prevDP = currDP;
            currDP = tmp;
            for (int j = 0; j < matrix[0].length; j++) {
                int l = (j -1 >= 0) ? prevDP[j - 1] : Integer.MAX_VALUE;
                int m = prevDP[j];
                int r = (j + 1 < matrix[0].length) ? prevDP[j + 1] : Integer.MAX_VALUE;
                currDP[j] = minOfThree(l, m, r) + matrix[i][j];
            }
        }
        // Find the minimum value
        int minSum = Integer.MAX_VALUE;
        for (int j = 0; j < currDP.length; j++) {
            if (currDP[j] < minSum)
                minSum = currDP[j];
        }
        return minSum;
    }

    private int minOfThree(int a, int b, int c) {
        int min = (a < b) ? a : b;
        return (min < c) ? min : c;
    }
}
