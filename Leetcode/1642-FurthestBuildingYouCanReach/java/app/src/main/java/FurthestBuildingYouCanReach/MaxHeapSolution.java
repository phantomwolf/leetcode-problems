package FurthestBuildingYouCanReach;

import java.util.Comparator;
import java.util.PriorityQueue;

public class MaxHeapSolution {
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        // Max heap
        PriorityQueue<Integer> maxPQ = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                return b - a;
            }
        });
        for (int i = 0; i < heights.length - 1; i++) {
            int diff = heights[i + 1] - heights[i];
            if (diff <= 0) {
                continue;
            }
            maxPQ.add(diff);
            bricks -= diff;
            while (bricks < 0 && ladders > 0) {
                // Place ladder to the highest gap and get the bricks back
                bricks += maxPQ.remove();
                ladders--;
            }
            if (bricks < 0) {
                // Impossible to reach heights[i+1]
                return i;
            }
        }
        return heights.length - 1;
    }
}
