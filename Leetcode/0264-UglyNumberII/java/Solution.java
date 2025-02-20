public class Solution {
    public int nthUglyNumber(int n) {
        // Define uglys[n-1] as the nth ugly number
        int[] uglys = new int[n];
        // Base case
        uglys[0] = 1;
        // 3 pointers for the multiplies of 2, 3, 5
        int index2 = 0, index3 = 0, index5 = 0;
        int next2 = 2, next3 = 3, next5 = 5;
        // Generate ugly numbers until we reach the nth one
        for (int i = 1; i < n; i++) {
            // Find the next ugly number
            uglys[i] = Math.min(
                    next2,
                    Math.min(next3, next5));
            // Since there are duplicates in different sequences, uglys[i] might equal to both next2 and next3, or even all three next values.
            // And it's guaranteed that within each individual sequence, there's no duplicates.
            // Conclusion: we need to compare uglys[i] with all three values: next2, next3, next5. This way, duplicates will be skipped.
            if (uglys[i] == next2) {
                index2++;
                next2 = uglys[index2] * 2;
            }
            if (uglys[i] == next3) {
                index3++;
                next3 = uglys[index3] * 3;
            }
            if (uglys[i] == next5) {
                index5++;
                next5 = uglys[index5] * 5;
            }
        }
        return uglys[n - 1];
    }
}
