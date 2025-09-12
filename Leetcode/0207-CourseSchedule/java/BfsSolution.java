package main;

class BfsSolution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        // Build graph
        List<Integer>[] graph = new ArrayList[numCourses];
        for (int i = 0; i < numCourses; i++) {
            graph[i] = new ArrayList<Integer>();
        }
        // Add edges
        int[] indegrees = new int[numCourses];
        for (int[] pre : prerequisites) {
            int from = pre[0];
            int to = pre[1];
            // edge means "depends on"
            indegrees[to]++;
            graph[from].add(to);
        }

        // BFS
        ArrayDeque<Integer> queue = new ArrayDeque<>();
        // Enqueue all nodes with 0 indegree
        for (int i = 0; i < numCourses; i++) {
            if (indegrees[i] == 0) {
                queue.add(i);
            }
        }

        // Track number of nodes visited
        int visited = 0;
        while (!queue.isEmpty()) {
            int node = queue.remove();
            visited++;
            // Reduce indegrees
            for (int neighbor : graph[node]) {
                indegrees[neighbor]--;
                if (indegrees[neighbor] == 0) {
                    queue.add(neighbor);
                }
            }
        }
        // Check if all nodes are visited
        if (visited < numCourses) {
            // Not all nodes visited. Cycle detected.
            return false;
        }
        return true;
    }
}
