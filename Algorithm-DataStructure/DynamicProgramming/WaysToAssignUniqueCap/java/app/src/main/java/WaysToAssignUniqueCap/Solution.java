package WaysToAssignUniqueCap;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Solution {
    /*
     * @param caps      cap collection of each person
     * @return how many ways to assign unique caps
     */
    public int assignUniqueCap(int[][] caps) {
        int N = caps.length;
        Set<Integer>[] capSet = new HashSet[N];
        for (int i = 0; i < N; i++) {
            capSet[i] = new HashSet<>();
            for (int j = 0; j < caps[i].length; j++) {
                capSet[i].add(caps[i][j]);
            }
        }
        long[][] dp = new long[101][1 << N];
        // base case
        for (int i = 0; i <= 100; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= 100; i++) {
            for (int mask = 1; mask < (1 << N); mask++) {
                dp[i][mask] = dp[i - 1][mask];
                for (int j = 0; j < N; j++) {
                    if (((1 << j) & mask) == 0)
                        continue;
                    // clear j bit of mask
                    int newMask = (1 << j) ^ mask;
                    if (capSet[j].contains(i)) {
                        // If j-th person has i-th hap in the collection
                        dp[i][mask] += dp[i - 1][newMask];
                        dp[i][mask] %= 1000000007;
                    }
                }
            }
        }

        for (int i = 0; i < dp.length; i++) {
            System.out.printf("dp[%d]: %s%n", i, Arrays.toString(dp[i]));
        }

        return (int) dp[100][(1 << N) - 1];
    }
}
