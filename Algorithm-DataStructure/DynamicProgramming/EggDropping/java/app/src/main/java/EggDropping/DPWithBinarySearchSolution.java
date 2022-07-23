package EggDropping;

public class DPWithBinarySearchSolution {
    Integer[][] memo;

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
        int res = searchOptimalRes(k, n);
        // update memo
        memo[k][n] = res;
        return res;
    }

    private int searchOptimalRes(int k, int n) {
        int lo = 1, hi = n;
        // we should never exclude mi from the search
        while (lo + 1 < hi) {
            int mi = lo + (hi - lo) / 2;
            int a = dp(k - 1, mi - 1);
            int b = dp(k, n - mi);
            if (a < b) {
                lo = mi;
            } else if (a > b) {
                hi = mi;
            } else {
                return Math.max(dp(k - 1, mi - 1), dp(k, n - mi)) + 1;
            }
        }
        // the optimal x will be either lo or hi
        int res1 = Math.max(dp(k - 1, lo - 1), dp(k, n - lo)) + 1;
        int res2 = Math.max(dp(k - 1, hi - 1), dp(k, n - hi)) + 1;
        if (res1 < res2) {
            return res1;
        }
        return res2;
    }
}