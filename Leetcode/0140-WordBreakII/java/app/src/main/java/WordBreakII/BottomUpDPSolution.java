package WordBreakII;

import java.util.ArrayList;
import java.util.List;

public class BottomUpDPSolution {
    private List<String> result;

    public List<String> wordBreak(String s, List<String> wordDict) {
        TrieNode root = buildInvertedTrie(wordDict);
        List<String> dp[] = new ArrayList[s.length() + 1];
        // base case
        dp[0] = new ArrayList<String>();
        for (int i = 1; i <= s.length(); i++) {
            TrieNode node = root;
            StringBuilder sb = new StringBuilder();
            for (int j = i - 1; j >= 0; j--) {
                char c = s.charAt(j);
                node = node.children[c - 'a'];
                sb.append(c);
                if (node == null) {
                    break;
                }
                if (node.exists && dp[j] != null) {
                    if (dp[i] == null) {
                        dp[i] = new ArrayList<String>();
                    }
                    String postfix = new StringBuilder(sb).reverse().toString();
                    if (j == 0) {
                        dp[i].add(postfix);
                    } else {
                        for (String prefix : dp[j]) {
                            dp[i].add(String.join(" ", prefix, postfix));
                        }
                    }
                }
            }
        }
        return (dp[s.length()] == null) ? new ArrayList<String>() : dp[s.length()];
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
