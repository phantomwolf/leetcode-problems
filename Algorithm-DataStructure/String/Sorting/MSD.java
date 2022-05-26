package com.snowwolf;

import java.lang.*;
import java.util.*;
import java.util.stream.Collectors;

// Most significant digit sorting for variable-length strings
class MSD {
    private static int R = 256;
    private static String[] aux;

    // return 0 if out of range
    private static int charAt(final String s, int d) {
        if (d >= s.length()) {
            return -1;
        }
        return s.charAt(d);
    }

    public static String[] sort(String[] a) {
        aux = new String[a.length];
        sort(a, 0, a.length - 1, 0);
        return a;
    }

    private static void sort(String[] a, int lo, int hi, int d) {
        if (lo >= hi) {
            // Already sorted
            return;
        }
        System.out.printf("lo: %d, hi: %d\n", lo, hi);
        int[] count = new int[R + 2];
        // calculate frequency
        for (int i = lo; i <= hi; i++) {
            count[charAt(a[i], d) + 2]++;
        }
        System.out.println(Arrays.stream(count).boxed().collect(Collectors.toList()).subList(49, 122));
        // convert frequency to index
        for (int i = 1; i < count.length; i++) {
            count[i] += count[i - 1];
        }
        System.out.println(Arrays.stream(count).boxed().collect(Collectors.toList()).subList(49, 122));
        // write to aux
        for (int i = lo; i <= hi; i++) {
            aux[count[charAt(a[i], d) + 1]++] = a[i];
        }
        System.out.println(Arrays.stream(aux).collect(Collectors.toList()));
        // write back
        for (int i = lo; i <= hi; i++) {
            a[i] = aux[i - lo];
        }
        System.out.println(Arrays.stream(a).collect(Collectors.toList()));
        // recursively sort other characters
        for (int i = 0; i < 256; i++) {
            sort(a, lo + count[i], lo + count[i + 1] - 1, d + 1);
        }
    }
}