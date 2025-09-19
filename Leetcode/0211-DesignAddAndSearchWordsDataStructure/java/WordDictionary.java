import java.util.*;

record MemoKey(TrieNode node, int i) {
}

class TrieNode {
    public TrieNode[] children = new TrieNode[128];
    public boolean isWord = false;
}

public class WordDictionary {
    private TrieNode root;

    public WordDictionary() {
        root = new TrieNode();
    }

    public void addWord(String word) {
        TrieNode node = root;
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);

            // Add new node if needed
            if (node.children[c] == null) {
                node.children[c] = new TrieNode();
            }
            node = node.children[c];
        }
        // Mark as word
        node.isWord = true;
    }

    public boolean search(String word) {
        Map<MemoKey, Boolean> memo = new HashMap<>();
        return dfs(word, 0, root, memo);
    }

    private boolean dfs(String pattern, int i, TrieNode node, Map<MemoKey, Boolean> memo) {
        // Base cases
        if (node == null) {
            return false;
        }
        if (i == pattern.length()) {
            return node.isWord;
        }

        // Query memo
        MemoKey memoKey = new MemoKey(node, i);
        if (memo.containsKey(memoKey)) {
            return memo.get(memoKey);
        }

        char c = pattern.charAt(i);

        // Print current char of this recursive call for debugging
        System.out.print(c);

        boolean res = false;
        if (c >= 'a' && c <= 'z') {
            res = dfs(pattern, i + 1, node.children[c], memo);
            memo.put(new MemoKey(node, i), res);
            return res;
        } else if (c == '.') {
            for (char d = 'a'; d <= 'z'; d++) {
                res = dfs(pattern, i + 1, node.children[d], memo);
                if (res) {
                    break;
                }
            }
            memo.put(new MemoKey(node, i), res);
            return res;
        }

        // Wildcard '*'. Similar to dynamic programming.
        // Case 1: * matches 0 characters
        res = dfs(pattern, i + 1, node, memo);
        if (!res) {
            // Case 2: * matches 1 character in this recursive call
            for (char d = 'a'; d <= 'z'; d++) {
                res = dfs(pattern, i, node.children[d], memo);
                if (res) {
                    break;
                }
            }
        }
        memo.put(new MemoKey(node, i), res);
        return res;
    }

    public static void main(String[] args) throws Exception {
        WordDictionary wordDictionary = new WordDictionary();
        wordDictionary.addWord("bad");
        wordDictionary.addWord("dad");
        wordDictionary.addWord("mad");
        wordDictionary.addWord("x");

        List<TestCase> testCases = List.of(
            new TestCase("pad", false),
            new TestCase("bad", true),
            new TestCase(".ad", true),
            new TestCase("b..", true),
            new TestCase("*x", true),
            new TestCase("x*", true),
            new TestCase("*", true),
            new TestCase("m*d", true),
            new TestCase("*a*", true),
            new TestCase("m*x", false),
            new TestCase("", false)
        );
        for (TestCase tc : testCases) {
            boolean res = wordDictionary.search(tc.pattern());
            System.out.printf("\nPattern '%s', expected '%s', actual '%s'\n", tc.pattern(), tc.expected(), res);
            if (res != tc.expected()) {
                throw new Exception(String.format("Pattern '%s' should return %s, actual %s", tc.pattern(), tc.expected(), res));
            }
        }
        System.out.println("All tests passed!");
    }
}

record TestCase(String pattern, boolean expected) {}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */