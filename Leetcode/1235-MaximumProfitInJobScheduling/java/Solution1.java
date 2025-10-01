class Solution1 {
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = profit.length;
        int[][] jobs = new int[n][3];
        for (int i = 0; i < n; i++) {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }

        // Sort jobs by end time
        Arrays.sort(jobs, (a, b) -> a[1] - b[1]);

        // dp[i]: max profit using jobs[0, i), exclusive
        int[] dp = new int[n+1];
        // dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            // Linearly search for jobs[j-1] that doesn't conflict with jobs[i-1]
            int j = i-1;
            while (j >= 0) {
                if (j == 0 || jobs[j-1][1] <= jobs[i-1][0]) {
                    // no conflict
                    break;
                }
                j--;
            }
            dp[i] = Math.max(dp[j] + jobs[i-1][2], dp[i-1]);
        }
        return dp[n];
    }
}
