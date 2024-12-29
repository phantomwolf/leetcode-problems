import java.util.AbstractMap.SimpleEntry;

class Solution {
    public int shortestDistance(int[][] maze, int[] start, int[] destination) {
        int[][] dist = new int[maze.length][maze[0].length];
        for (int[] arr : dist) {
            Arrays.fill(arr, Integer.MAX_VALUE);
        }
        dist[start[0]][start[1]] = 0;
        PriorityQueue<SimpleEntry<int[], Integer>> pq = new PriorityQueue<>((a, b) -> a.getValue() - b.getValue());
        pq.add(new SimpleEntry<>(start, 0));
        int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!pq.isEmpty()) {
            SimpleEntry<int[], Integer> se = pq.poll();
            int[] pos = se.getKey();
            int distance = se.getValue();
            if (dist[pos[0]][pos[1]] < distance) {
                // Ignore this node because we've already reached it through a shorter path
                continue;
            }
            // Neighboring nodes
            for (int[] dir : dirs) {
                int x = pos[0] + dir[0];
                int y = pos[1] + dir[1];
                int weight = 1;
                while (x >= 0 && x < maze.length && y >= 0 && y < maze[0].length && maze[x][y] != 1) {
                    x += dir[0];
                    y += dir[1];
                    weight++;
                }
                x -= dir[0];
                y -= dir[1];
                weight--;
                if (dist[x][y] > dist[pos[0]][pos[1]] + weight) {
                    dist[x][y] = dist[pos[0]][pos[1]] + weight;
                    // When we find a shorter path, we simply add the new distance into the priority queue.
                    // There's no need to modify the old entry, or remove it from the priority queue, since it's time consuming.
                    // We've already added a protection which ignores 
                    pq.add(new SimpleEntry<int[], Integer>(new int[]{x, y}, dist[x][y]));
                }
            }
        }
        return dist[destination[0]][destination[1]] == Integer.MAX_VALUE ? -1 : dist[destination[0]][destination[1]];
    }
}
