class TrieNode {
    TrieNode[] children = new TrieNode[26];
    String word = null;
}

class Solution {
    private TrieNode root = new TrieNode();

    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        // Insert products
        for (String p : products) {
            TrieNode node = root;
            for (int i = 0; i < p.length(); i++) {
                char c = (char) (p.charAt(i) - 'a');
                if (node.children[c] == null) {
                    node.children[c] = new TrieNode();
                }
                node = node.children[c];
            }
            node.word = p;
        }

        // Search
        List<List<String>> res = new ArrayList<>();
        TrieNode node = root;
        for (int i = 0; i < searchWord.length(); i++) {
            char c = (char) (searchWord.charAt(i) - 'a');
            if (node != null) {
                node = node.children[c];
            }
            if (node == null) {
                res.add(new ArrayList<>());
                continue;
            }

            // Get suggestions
            List<String> suggestions = new ArrayList<>();
            dfs(node, suggestions);
            res.add(suggestions);
        }
        return res;
    }

    private void dfs(TrieNode root, List<String> res) {
        if (root == null) {
            return;
        }
        if (res.size() == 3) {
            return;
        }
        if (root.word != null) {
            res.add(root.word);
            if (res.size() == 3) {
                return;
            }
        }

        // Neighbors
        for (char c = 0; c < 26; c++) {
            dfs(root.children[c], res);
        }
    }
}