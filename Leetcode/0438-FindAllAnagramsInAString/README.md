# 438. Find All Anagrams in a String
Given two strings s and p, return an array of all the start indices of p's

in s. You may return the answer in any order.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

Constraints:

* 1 <= s.length, p.length <= 3 * 104
* s and p consist of lowercase English letters.

## Solution: sliding window
First, record the amount of each character inside string p.

Then we use sliding window technique. Use [left, right) to represent the sliding window. Algorithm:

    for right < len(s) {
        // Expand window by adding s[right] to it
        ...
        for right-left >= len(p) {
            // Shrink window by removing s[left] from it
            ...
        }
    }

