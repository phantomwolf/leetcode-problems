package com.snowwolf;

import java.lang.*;

public class KruskalMain {
    public static void main(String[] args) {
        int V = 4;
        int[][] edges = {
                //{0, 1, 5}, {0, 2, 6}, {1, 2, 1},
                {0, 1, 3}, {2, 3, 4},
        };
        Kruskal kruskal = new Kruskal(V, edges);
        if (kruskal.cost == -1) {
            System.out.println("Minimum spanning tree doesn't exist");
            return;
        }
        System.out.printf("Minimum spanning tree: %s, cost: %d\n", kruskal.mst, kruskal.cost);
    }
}
