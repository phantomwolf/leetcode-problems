package com.snowwolf;

import java.lang.*;
import java.util.Arrays;

public class DijkstraMain {
    public static void main(String[] args) {
        int V = 4;
        int s = 1;
        int edges[][] = {
                {1, 0, 1}, {1, 2, 1}, {2, 3, 1},
        };
        DirectedGraph directedGraph = new DirectedGraph(V, edges);
        int[] dist = directedGraph.dijkstra(1);
        System.out.println(Arrays.toString(dist));
    }
}
