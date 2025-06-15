public class Solution1 {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> anagrams = new HashMap<>();
        for (String s : strs) {
            // Generate a key for each string
            byte[] count = new byte[26];
            for (char c : s.toCharArray()) {
                count[c-'a']++;
            }
            String key = new String(count);
            if (!anagrams.containsKey(key)) {
                anagrams.put(key, new ArrayList<String>());
            }
            anagrams.get(key).add(s);
        }
        List<List<String>> result = new ArrayList<>();
        for (Map.Entry<String, List<String>> entry : anagrams.entrySet()) {
            result.add(entry.getValue());
        }
        return result;
    }
}