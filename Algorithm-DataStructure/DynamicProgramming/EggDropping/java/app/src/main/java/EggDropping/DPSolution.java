package EggDropping;

class DPSolution {
    private Integer memo[][];
    public int superEggDrop(int k, int n) {
        memo = new Integer[k + 1][n + 1];
        return dp(k, n);
    }

    /*
     * @param k     number of eggs
     * @param n     number of floors
     */
    private int dp(int k, int n) {
        // base cases
        if (k == 1) {
            // Only 1 egg. We have to drop the egg sequentially from the 1st floor to the last.
            return n;
        }
        if (n <= 1) {
            // If n == 0, no floor needs to be tested: return 0
            // If n == 1, only 1 floor. We just need to do 1 trial. Return 1
            return n;
        }
        // Read memo
        if (memo[k][n] != null) {
            return memo[k][n];
        }
        // Dynamic programming
        int min = Integer.MAX_VALUE;
        for (int x = 1; x <= n; x++) {
            // Suppose we drop the egg on x-th floor,
            // if the egg breaks, we check the remaining x-1 lower floors with k-1 eggs;
            // if the egg doesn't break, we check the remaining n-x higher floors with k eggs
            int res = 1 + Math.max(dp(k - 1, x - 1), dp(k, n - x));
            if (res < min) {
                min = res;
            }
        }
        // update memo
        memo[k][n] = min;
        return min;
    }
}