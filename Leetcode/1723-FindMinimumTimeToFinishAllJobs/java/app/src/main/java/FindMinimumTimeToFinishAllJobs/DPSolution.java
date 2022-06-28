package FindMinimumTimeToFinishAllJobs;

public class DPSolution {
    public int minimumTimeRequired(int[] jobs, int k) {
        // Calculate the sum of all subsets
        int[] sum = new int[1 << jobs.length];
        for (int mask = 0; mask < (1 << jobs.length); mask++) {
            for (int j = 0; j < jobs.length; j++) {
                if (((1 << j) & mask) != 0) {
                    sum[mask] += jobs[j];
                }
            }
        }
        // Define dp[i][j] as the minimum possible maximum working time of assigning subset j to i workers
        // j is a bitmap representing a subset of jobs; i is the number of workers
        int[][] dp = new int[k + 1][1 << jobs.length];
        // base case: only 1 worker
        for (int mask = 0; mask < (1 << jobs.length); mask++) {
            dp[1][mask] = sum[mask];
        }
        for (int i = 2; i <= k; i++) {
            for (int mask = 0; mask < (1 << jobs.length); mask++) {
                // Since dp[i][mask] <= dp[i - 1][mask]
                dp[i][mask] = dp[i - 1][mask];
                for (int subset = mask; subset > 0; subset = (subset - 1) & mask) {
                    // Each time calculate a subset of mask
                    dp[i][mask] = Math.min(dp[i][mask], Math.max(dp[i - 1][mask - subset], sum[subset]));
                }
            }
        }
        return dp[k][(1 << jobs.length) - 1];
    }
}
