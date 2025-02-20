package com.snowwolf;

import java.lang.*;

public class Main {
    public static void main(String[] args) {
        UnionFindWithPathCompression uf = new UnionFindWithPathCompression(10);
        int[][] edges = {{4, 3}, {3, 8}, {6, 5}, {9, 4}, {2, 1}, {8, 9}, {5, 0}, {7, 2}, {6, 1}, {1, 0}, {6, 7}};
        for (int[] edge : edges) {
            uf.union(edge[0], edge[1]);
        }
        System.out.printf("Connected component count: %d\n", uf.count());
    }
}
