package com.snowwolf;

import java.util.List;

class TrieNode {
    public boolean exists = false;
    public TrieNode[] children = new TrieNode[26];
}

class DPWithTrieSolution {
    public boolean wordBreak(String s, List<String> wordDict) {
        TrieNode trie = buildInvertedTrie(wordDict);
        // dp[i] indicates if it's possible to do word break for a substring with length i
        boolean[] dp = new boolean[s.length() + 1];
        // base case
        dp[0] = true;

        for (int i = 1; i <= s.length(); i++) {
            TrieNode node = trie;
            for (int j = i - 1; j >= 0; j--) {
                char c = s.charAt(j);
                node = node.children[c - 'a'];
                if (node == null) {
                    break;
                }
                if (node.exists && dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }

    private TrieNode buildInvertedTrie(List<String> wordDict) {
        TrieNode root = new TrieNode();
        for (String word : wordDict) {
            TrieNode node = root;
            for (int i = word.length() - 1; i >= 0; i--) {
                char c = word.charAt(i);
                if (node.children[c - 'a'] == null) {
                    node.children[c - 'a'] = new TrieNode();
                }
                node = node.children[c - 'a'];
            }
            node.exists = true;
        }
        return root;
    }
}