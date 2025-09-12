public class Solution {
    public int[][] merge(int[][] intervals) {
        // Corner case
        if (intervals.length == 1) {
            return intervals;
        }

        // Sort intervals by their start time
        Arrays.sort(intervals, (a, b) -> {
            return a[0] - b[0];
        });

        int i = 1;
        for (int j = 1; j < intervals.length; j++) {
            if (intervals[i-1][1] >= intervals[j][0]) {
                // Merge
                intervals[i-1][1] = Math.max(intervals[i-1][1], intervals[j][1]);
            } else {
                // New non-overlapping interval
                intervals[i] = intervals[j];
                i++;
            }
        }
        
        int[][] res = Arrays.copyOfRange(intervals, 0, i);
        return res;
    } 
}
