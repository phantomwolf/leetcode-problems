package com.snowwolf;

import java.lang.*;
import java.util.*;
import java.util.stream.Collectors;

// Least significant digit sorting for fixed-length strings
class LSD {
    // @param a: strings to be sorted
    // @param W: length of strings
    public static String[] sort(String[] a, int W) {
        String[] aux = new String[a.length];
        int[] count = new int[257];
        for (int d = W - 1; d >= 0; d--) {
            // reset count array
            Arrays.fill(count, 0);
            // record the count of each char
            for (int i = 0; i < a.length; i++) {
                count[a[i].charAt(d) + 1]++;
            }
            // convert count to index
            for (int i = 1; i < count.length; i++) {
                count[i] += count[i - 1];
            }
            // Write each string to aux
            for (int i = 0; i < a.length; i++) {
                aux[count[a[i].charAt(d)]++] = a[i];
            }
            // Switch aux and input array
            String[] tmp = a;
            a = aux;
            aux = tmp;
        }
        return a;
    }
}
