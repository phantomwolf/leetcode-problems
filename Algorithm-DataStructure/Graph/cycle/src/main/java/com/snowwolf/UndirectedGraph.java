package com.snowwolf;

import java.util.*;

public class UndirectedGraph {
    List<Integer>[] adj;

    // Number of vertice
    int V;
    // Number of edges
    int E;

    // Record the previous vertex of each vertex
    int[] edgeTo;

    // All vertice in the cycle(if any)
    List<Integer> cycle;

    public UndirectedGraph(int V) {
        this.V = V;
        adj = new LinkedList[V];
        for (int v = 0; v < V; v++) {
            adj[v] = new LinkedList<>();
        }
        edgeTo = new int[V];
    }

    public UndirectedGraph(int V, int edges[][]) {
        this(V);
        for (int[] edge : edges) {
            addEdge(edge[0], edge[1]);
        }
    }

    public void addEdge(int from, int to) {
        adj[from].add(to);
        adj[to].add(from);
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

    public boolean isCyclic() {
        boolean[] visited = new boolean[V];
        for (int v = 0; v < V; v++) {
            if (!visited[v]) {
                edgeTo[v] = -1;
                if (isCyclic(v, -1, visited))
                    return true;
            }
        }
        return false;
    }

    // @param p     previous vertex of v
    public boolean isCyclic(int v, int p, boolean[] visited) {
        System.out.printf("isCyclic(%d, %d, %s)\n", v, p, Arrays.toString(visited));
        visited[v] = true;
        for (int w : adj[v]) {
            if (!visited[w]) {
                edgeTo[w] = v;
                if (isCyclic(w, v, visited))
                    return true;
            } else if (w != p) {
                // add all vertice in the cycle to a list
                cycle = new ArrayList<>();
                for (int u = v; u != w; u = edgeTo[u]) {
                    cycle.add(u);
                }
                cycle.add(w);
                Collections.reverse(cycle);
                return true;
            }
        }
        return false;
    }
}
