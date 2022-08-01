package minimumnumberoftapstoopentowateragarden;

import java.util.Arrays;

public class Solution {
    public int minTaps(int n, int[] ranges) {
        // taps[from] = to: there's a tap which can water range [from, to]
        int[] taps = new int[n + 1];
        Arrays.fill(taps, -1);
        for (int i = 0; i < ranges.length; i++) {
            // i-th tap can water range [from, to]
            int from = Math.max(i - ranges[i], 0);
            int to = Math.min(i + ranges[i], n);
            // Only records the tap which can water the maximum range
            taps[from] = Math.max(taps[from], to);
        }
        int start = 0, end = 0;
        int res = 0;
        while (end < n) {
            int nextEnd = Integer.MIN_VALUE;
            for (int i = start; i <= end; i++) {
                nextEnd = Math.max(nextEnd, taps[i]);
            }
            if (nextEnd <= end) {
                // can't go any farther
                return -1;
            }
            start = end + 1;
            end = nextEnd;
            res++;
        }
        return res;
    }
}