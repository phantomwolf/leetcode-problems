package MinimumWorkSessions;

class TopDownSolution {
    private Integer[][] memo;
    private int sessionTime;

    public int minSessions(int[] tasks, int sessionTime) {
        memo = new Integer[1 << tasks.length][sessionTime + 1];
        this.sessionTime = sessionTime;
        return dp(tasks, (1 << tasks.length) - 1, 0);
    }

    /**
     * @param mask      a bitmask which represents a subset of tasks
     * @param rt        remaining time of the current work session
     * @return          minimum work sessions needed
     */
    private int dp(int[] tasks, int mask, int rt) {
        // base case
        if (mask == 0) {
            return 0;
        }
        // Use memo
        if (memo[mask][rt] != null) {
            return memo[mask][rt];
        }
        // Worst case: each task needs a work session
        int ans = tasks.length;
        for (int i = 0; i < tasks.length; i++) {
            if (((1 << i) & mask) != 0) {
                // handle tasks[i]
                int newMask = (~(1 << i)) & mask;
                if (tasks[i] <= rt) {
                    ans = Math.min(ans, dp(tasks, newMask, rt - tasks[i]));
                } else {
                    ans = Math.min(ans, 1 + dp(tasks, newMask, sessionTime - tasks[i]));
                }
            }
        }
        memo[mask][rt] = ans;
        return ans;
    }
}