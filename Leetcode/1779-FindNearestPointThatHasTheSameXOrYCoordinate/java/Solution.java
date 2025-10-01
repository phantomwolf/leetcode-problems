class Solution {
    public int nearestValidPoint(int x, int y, int[][] points) {
        int minDist = Integer.MAX_VALUE;
        int index = -1;

        for (int i = 0; i < points.length; i++) {
            if (points[i][0] != x && points[i][1] != y) {
                // Invalid point
                continue;
            }

            int dist = (points[i][0] == x) ? Math.abs(y - points[i][1]) : Math.abs(x - points[i][0]);
            if (dist < minDist) {
                minDist = dist;
                index = i;
            }
        }
        return index;
    }
}