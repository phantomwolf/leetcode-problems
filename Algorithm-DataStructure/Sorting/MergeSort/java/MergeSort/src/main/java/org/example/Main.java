package org.example;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int[] nums = {2,4,3,5,1};
        TopDownMergeSort.mergeSort(nums);
        System.out.println(Arrays.toString(nums));
    }
}