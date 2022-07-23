package JumpGameIV;

import java.util.*;

public class BFSSolution {
    public int minJumps(int[] arr) {
        // Value to index mapping
        Map<Integer, List<Integer>> valToIndex = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            if (!valToIndex.containsKey(arr[i])) {
                valToIndex.put(arr[i], new ArrayList<>());
            }
            valToIndex.get(arr[i]).add(i);
        }
        Set<Integer> visited = new HashSet<>();
        Queue<Integer> q = new ArrayDeque<>();
        // Add first vertex index to queue
        q.add(0);
        visited.add(0);
        int steps = 0;
        while (!q.isEmpty()) {
            // Deque all the vertice for this step
            int size = q.size();
            for (int sz = q.size(); sz > 0; sz--) {
                int i = q.remove();
                int val = arr[i];
                if (i == arr.length - 1) {
                    return steps;
                }
                // Given a vertex arr[i], it can reach arr[i-1], arr[i+1], and all vertex with the same value
                if (i - 1 >= 0 && !visited.contains(i - 1)) {
                    visited.add(i - 1);
                    q.add(i - 1);
                }
                if (i + 1 < arr.length && !visited.contains(i + 1)) {
                    visited.add(i + 1);
                    q.add(i + 1);
                }
                for (int j : valToIndex.get(val)) {
                    if (!visited.contains(j)) {
                        visited.add(j);
                        q.add(j);
                    }
                }
                // clear
                valToIndex.get(val).clear();
            }
            steps++;
        }
        return -1;
    }
}