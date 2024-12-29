package com.snowwolf;

import java.lang.reflect.Array;
import java.util.*;

// Undirected edge
class Edge implements Comparable<Edge> {
    // 2 vertice of the edge
    public int v;
    public int w;

    // cost of the edge
    public int cost;

    public Edge(int v, int w, int cost) {
        this.v = v;
        this.w = w;
        this.cost = cost;
    }

    @Override
    public String toString() {
        return String.format("%d-%d(%d)", v, w, cost);
    }

    public int compareTo(Edge other) {
        return cost - other.cost;
    }
}

public class Kruskal {
    // Number of vertice
    int V;

    // All edges of the minimum spanning tree
    public List<Edge> mst;

    // Total cost of the minimum spanning tree
    int cost;

    public Kruskal(int V, int edges[][]) {
        this.V = V;
        cost = 0;
        mst = new ArrayList<>(V);

        ArrayList<Edge> col = new ArrayList<>();
        for (int[] edge : edges) {
            col.add(new Edge(edge[0], edge[1], edge[2]));
        }
        // Kruskal
        UnionFind uf = new UnionFind(V);
        PriorityQueue<Edge> pq = new PriorityQueue<>(col);
        while (!pq.isEmpty() && mst.size() < V - 1) {
            Edge edge = pq.remove();
            // Ignore invalid edges
            if (uf.connected(edge.v, edge.w))
                continue;
            uf.union(edge.v, edge.w);
            mst.add(edge);
            cost += edge.cost;
        }
        // Check if minimum spanning tree exists
        if (uf.count != 1) {
            mst.clear();
            cost = -1;
        }
    }

    public List<Edge> mst() {
        return this.mst;
    }

    public int cost() {
        return this.cost;
    }
}
