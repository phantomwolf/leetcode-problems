package com.snowwolf;

import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public class DirectedGraph {
    // Adjacent list
    List<Integer>[] adj;

    // Number of vertice
    int V;
    // Number of edges
    int E;

    List<Integer> topologySortResult;

    public DirectedGraph(int V) {
        this.V = V;
        adj = new LinkedList[V];
        for (int v = 0; v < V; v++) {
            adj[v] = new LinkedList<>();
        }
    }

    public DirectedGraph(int V, int edges[][]) {
        this(V);
        for (int[] edge : edges) {
            int from = edge[0], to = edge[1];
            addEdge(from, to);
        }
    }

    public void addEdge(int to, int from) {
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

    // Returns false if topology sort can't be done(cycle detected); otherwise, return true
    public boolean topologySort() {
        topologySortResult = new ArrayList<>();
        boolean[] visited = new boolean[V];
        boolean[] onPath = new boolean[V];
        for (int v = 0; v < V; v++) {
            if (!visited[v]) {
                if (!topologySort(v, visited, onPath)) {
                    // cycle detected
                    return false;
                }
            }
        }
        // Reverse sort result
        Collections.reverse(topologySortResult);
        return true;
    }

    // Returns false if topology sort can't be done(cycle detected); otherwise, return true
    private boolean topologySort(int v, boolean[] visited, boolean[] onPath) {
        visited[v] = true;
        onPath[v] = true;
        for (int w : adj[v]) {
            if (!visited[w]) {
                if (!topologySort(w, visited, onPath)) {
                    return false;
                }
            } else if (onPath[w]) {
                return false;
            }
        }
        topologySortResult.add(v);
        onPath[v] = false;
        return true;
    }
}
