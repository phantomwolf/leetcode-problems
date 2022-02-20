import java.lang.Math;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        final HashMap<Character, Integer> charCount = new HashMap<>();
        int duplicates = 0;
        int longestLength = 0;
        int left, right; // left and right bound of the sliding window
        for (left = 0, right = 0; right < s.length(); right++) {
            char currChar = s.charAt(right);
            charCount.put(currChar, charCount.getOrDefault(currChar, 0) + 1);
            if (charCount.get(currChar) == 2) {
                duplicates += 1;
                // Calculate length
                longestLength = Math.max(longestLength, right - left);
            }
            // Remove characters from the sliding window until there's no more duplicates
            while (duplicates > 0) {
                char c = s.charAt(left);
                charCount.put(c, charCount.get(c) - 1);
                if (charCount.get(c) == 1) {
                    duplicates -= 1;
                }
                left++;
            }
        }
        // edge case
        longestLength = Math.max(longestLength, right - left);
        return longestLength;
    }
}