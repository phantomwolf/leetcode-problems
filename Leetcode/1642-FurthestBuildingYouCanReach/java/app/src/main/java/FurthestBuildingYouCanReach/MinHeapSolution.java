package FurthestBuildingYouCanReach;

import java.util.PriorityQueue;

public class MinHeapSolution {
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        PriorityQueue<Integer> minPQ = new PriorityQueue<>();
        for (int i = 0; i < heights.length - 1; i++) {
            int diff = heights[i + 1] - heights[i];
            if (diff <= 0) {
                // No need to climb
                continue;
            }
            if (ladders > 0) {
                // Use a ladder when still available
                minPQ.add(diff);
                ladders--;
                continue;
            }
            // Use bricks
            if (!minPQ.isEmpty() && diff > minPQ.peek()) {
                // Swap the ladder here and use bricks for a previous climb
                bricks -= minPQ.remove();
                minPQ.add(diff);
            } else {
                bricks -= diff;
            }
            if (bricks < 0) {
                // Insufficient bricks to reach i+1
                return i;
            }
        }
        return heights.length - 1;
    }
}
