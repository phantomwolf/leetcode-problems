package com.snowwolf;

import java.util.ArrayList;
import java.util.Collection;

// Min heap by default
public class BinaryHeap<T extends Comparable> {
    private static int parent(int i) {
        return (i - 1) / 2;
    }

    private static int left(int p) {
        return p * 2 + 1;
    }

    private static int right(int p) {
        return p * 2 + 2;
    }

    ArrayList<T> heap;

    public BinaryHeap() {
        heap = new ArrayList<>();
    }

    public BinaryHeap(int capacity) {
        heap = new ArrayList<>(capacity);
    }

    private void exch(int i, int j) {
        T tmp = heap.get(i);
        heap.set(i, heap.get(j));
        heap.set(j, tmp);
    }

    public void add(T item) {
        heap.add(item);
        // Fix heap property
        int i = heap.size() - 1;
        while (i > 0) {
            int p = parent(i);
            if (heap.get(i).compareTo(heap.get(p)) >= 0)
                break;
            exch(i, p);
            i = p;
        }
    }

    // Remove the heap top item
    public T remove() {
        if (heap.size() == 0)
            return null;
        T result = heap.get(0);
        heap.set(0, heap.get(heap.size() - 1));
        heap.remove(heap.size() - 1);
        // Fix heap property
        int p = 0;
        while (left(p) < heap.size()) {
            int l = left(p), r = right(p);
            int i = l;
            if (r < heap.size() &&
                    heap.get(r).compareTo(heap.get(l)) < 0) {
                i = r;
            }
            if (heap.get(p).compareTo(heap.get(i)) < 0) {
                break;
            }
            exch(p, i);
            p = i;
        }
        return result;
    }

    public int size() {
        return heap.size();
    }
}
