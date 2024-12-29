package TravellingSalesmanProblem;

public class DPSolution {
    public int shortestRoute(int[][] dist) {
        int N = dist.length;
        // Define dp as the shortest route length to visit
        int[][] dp = new int[1 << N][N];
        for (int mask = 1; mask < (1 << N); mask++) {
            for (int i = 1; i < N; i++) {
                if ((mask & 1) == 0) {
                    // 0-th bit not set. Vertex 0 not included. Skip.
                    continue;
                }
                if (mask == ((1 << i) | 1)) {
                    // base case: only 2 bits set, including 0-th bit
                    dp[mask][i] = dist[0][i];
                    continue;
                }
                dp[mask][i] = Integer.MAX_VALUE;
                for (int j = 1; j < N; j++) {
                    if (((1 << j) & mask) == 0 || j == i) {
                        continue;
                    }
                    // clear j-th bit
                    int newMask = (1 << i) ^ mask;
                    dp[mask][i] = Math.min(dp[mask][i], dp[newMask][j] + dist[j][i]);
                }
            }
        }
        // Find shortest route
        int result = Integer.MAX_VALUE;
        for (int i = 1; i < N; i++) {
            result = Math.min(result, dp[(1 << N) - 1][i] + dist[i][0]);
        }
        return result;
    }
}
