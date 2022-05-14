class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        int[] diff = new int[1001];
        diff[0] = capacity;
        for (int[] trip : trips) {
            int num = trip[0], from = trip[1], to = trip[2] - 1;
            diff[from] -= num;
            if (to + 1 <= 1000) {
                diff[to + 1] += num;
            }
        }

        int prev = 0, curr;
        for (int i = 0; i <= 1000; i++) {
            curr = prev + diff[i];
            if (curr < 0) {
                return false;
            }
            prev = curr;
        }
        return true;
    }
}
