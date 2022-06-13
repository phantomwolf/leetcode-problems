package com.snowwolf;

import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        String s = "catsandog";
        List<String> wordDict = Arrays.asList("cats", "dog", "sand", "and", "cat");

        DPSolution dpSolution = new DPSolution();
        boolean possible = dpSolution.wordBreak(s, wordDict);
        System.out.printf("Possible: %s%n", possible);

        DPWithTrieSolution dpWithTrieSolution = new DPWithTrieSolution();
        possible = dpWithTrieSolution.wordBreak(s, wordDict);
        System.out.printf("Possible: %s%n", possible);
    }
}
