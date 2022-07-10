package MinimumWorkSessions;

public class BottomUpSolution {
    public int minSessions(int[] tasks, int sessionTime) {
        // Define dp[mask] as {minSession, minTimeOfLastSession}.
        // minSession is the minimum number of work sessions to finish a subset of tasks: mask
        // minTimeOfLastSession is the minimum time
        int[][] dp = new int[1 << tasks.length][2];
        // base case
        dp[0][0] = 1;   // start a new work session
        dp[0][1] = 0;   // work time of current session is 0 since no task has been added yet
        for (int mask = 1; mask < (1 << tasks.length); mask++) {
            dp[mask][0] = Integer.MAX_VALUE;
            dp[mask][1] = 0;
            for (int i = 0; i < tasks.length; i++) {
                if (((1 << i) & mask) == 0)
                    continue;
                // clear i bit
                int[] prev = dp[(1 << i) ^ mask];
                if (prev[1] + tasks[i] <= sessionTime) {
                    dp[mask] = min(dp[mask], new int[]{prev[0], prev[1] + tasks[i]});
                } else {
                    dp[mask] = min(dp[mask], new int[]{prev[0] + 1, tasks[i]});
                }
            }
        }
        return dp[(1 << tasks.length) - 1][0];
    }

    private int[] min(int[] d1, int[] d2) {
        if (d1[0] == d2[0])
            return (d1[1] < d2[1]) ? d1 : d2;
        return (d1[0] < d2[0]) ? d1 : d2;
    }
}
