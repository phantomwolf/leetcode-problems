package com.snowwolf;

import java.util.*;

public class DirectedGraph {
    List<Integer>[] adj;

    // Number of vertice
    int V;
    // Number of edges
    int E;

    // Record previous vertex in the path
    int[] edgeTo;

    // Vertice in the cycle
    List<Integer> cycle;

    public DirectedGraph(int V) {
        this.V = V;
        adj = new LinkedList[V];
        for (int v = 0; v < V; v++) {
            adj[v] = new LinkedList<>();
        }
        edgeTo = new int[V];
        cycle = new ArrayList<>();
    }

    public DirectedGraph(int V, int edges[][]) {
        this(V);
        for (int[] edge : edges) {
            addEdge(edge[0], edge[1]);
        }
    }

    public void addEdge(int from, int to) {
        adj[from].add(to);
        E++;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(String.format("%d:%s", 0, adj[0]));
        for (int v = 1; v < V; v++) {
            sb.append(String.format(", %d:%s", v, adj[v]));
        }
        return sb.toString();
    }

    // DFS
    public boolean isCyclic() {
        boolean[] visited = new boolean[V];
        boolean[] onPath = new boolean[V];
        for (int v = 0; v < V; v++) {
            // Ignore visited vertice
            if (visited[v])
                continue;
            if (isCyclic(v, visited, onPath))
                return true;
        }
        return false;
    }

    private boolean isCyclic(int v, boolean[] visited, boolean[] onPath) {
        onPath[v] = true;
        visited[v] = true;
        for (int w : adj[v]) {
            if (!visited[w]) {
                edgeTo[w] = v;
                boolean ret = isCyclic(w, visited, onPath);
                if (ret)
                    return true;
            } else if (onPath[w]) {
                // add all vertice in the cycle to a list
                for (int u = v; u != w; u = edgeTo[u]) {
                    cycle.add(u);
                }
                cycle.add(w);
                Collections.reverse(cycle);
                return true;
            }
        }
        onPath[v] = false;
        return false;
    }
}
