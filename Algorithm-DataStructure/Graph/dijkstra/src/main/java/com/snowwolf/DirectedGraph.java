package com.snowwolf;

import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;

class Edge implements Comparable<Edge> {
    // Vertex
    public int v;
    // Distance
    public int cost;

    public Edge(int v, int cost) {
        this.v = v;
        this.cost = cost;
    }
    @Override
    public int compareTo(Edge other) {
        return cost - other.cost;
    }
}

public class DirectedGraph {
    List<Edge>[] adj;

    // Number of vertice
    int V;
    // Number of edges
    int E;

    // Distance
    int[] dist;

    public DirectedGraph(int V) {
        this.V = V;
        adj = new LinkedList[V];
        for (int v = 0; v < V; v++) {
            adj[v] = new LinkedList<Edge>();
        }
    }

    public DirectedGraph(int V, int edges[][]) {
        this(V);
        for (int[] edge : edges) {
            addEdge(edge[0], edge[1], edge[2]);
        }
    }

    public void addEdge(int from, int to, int dist) {
        adj[from].add(new Edge(to, dist));
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

    // @param s     starting vertex
    public int[] dijkstra(int s) {
        boolean[] visited = new boolean[V];
        // Init dist[]
        dist = new int[V];
        for (int v = 0; v < V; v++) {
            dist[v] = Integer.MAX_VALUE;
        }
        dist[s] = 0;
        // Re-use Edge class to store vertice and their distance to s
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.add(new Edge(s, 0));
        while (!pq.isEmpty()) {
            Edge v = pq.remove();
            // Ignore visited vertex
            if (visited[v.v])
                continue;
            visited[v.v] = true;
            // Add neighbors to priority queue
            for (Edge w : adj[v.v]) {
                if (visited[w.v])
                    continue;
                if (dist[w.v] > dist[v.v] + w.cost) {
                    dist[w.v] = dist[v.v] + w.cost;
                    pq.add(new Edge(w.v, dist[w.v]));
                }
            }
        }
        return dist;
    }
}
