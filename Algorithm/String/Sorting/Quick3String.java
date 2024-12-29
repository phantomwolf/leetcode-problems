package com.snowwolf;

import java.lang.*;
import java.util.*;
import java.util.stream.Collectors;

class Quick3String {
    private static int charAt(final String s, int d) {
        if (d < s.length()) {
            return s.charAt(d);
        }
        return -1;
    }

    private static void exch(String[] a, int i, int j) {
        if (i == j) {
            return;
        }
        String tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    public static void sort(String[] a) {
        sort(a, 0, a.length - 1, 0);
    }

    public static void sort(String[] a, int lo, int hi, int d) {
        if (lo >= hi) {
            return;
        }
        int left = lo, right = hi;
        int pivot = charAt(a[lo], d);
        for (int i = lo + 1; i <= right; i++) {
            if (charAt(a[i], d) < pivot) {
                exch(a, i++, left++);
            } else if (charAt(a[i], d) > pivot) {
                exch(a, i, right--);
            } else {
                i++;
            }
        }
        sort(a, lo, left - 1, d);
        if (d >= 0) {
            sort(a, left, right, d + 1);
        }
        sort(a, right + 1, hi, d);
    }
}