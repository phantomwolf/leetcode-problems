package closestnodetopathintree;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    public int[] closestNode(int n, int[][] edges, int[][] query) {
        List<Integer>[] graph = buildGraph(n, edges);

    }

    private List<Integer>[] buildGraph(int n, int[][] edges) {
        List<Integer>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int[] edge : edges) {
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
        }
        return graph;
    }

    private int[] dijkstra(List<Integer>[] graph, int src) {
        int[] dist = new int[graph.length];
        dist[src] = 0;
    }
}
