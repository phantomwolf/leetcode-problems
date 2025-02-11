class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        // Edge case
        if (n <= 2) {
            List<Integer> result = new ArrayList<>();
            for (int v = 0; v < n; v++) {
                result.add(v);
            }
            return result;
        }
        // Build undirected graph
        Set<Integer>[] graph = new HashSet[n];
        for (int v = 0; v < n; v++) {
            graph[v] = new HashSet<>();
        }
        // Add edges
        for (int[] edge : edges) {
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
        }
        // BFS
        Queue<Integer> q = new LinkedList<>();
        // Add leaves to queue
        for (int v = 0; v < n; v++) {
            if (graph[v].size() == 1) {
                q.add(v);
            }
        }
        // n vertice remaining
        int remain = n;
        while (remain > 2) {
            // Each time dequeue all items
            int size = q.size();
            remain -= size;
            while (size > 0) {
                int leaf = q.remove();
                // Remove leaf from all its neighbor's edges
                for (int neighbor : graph[leaf]) {
                    graph[neighbor].remove(leaf);
                    // New leaf
                    if (graph[neighbor].size() == 1) {
                        q.add(neighbor);
                    }
                }
                size--;
            }
        }
        List<Integer> list = new ArrayList();
        list.addAll(q);
        return list;
    }}

    

    