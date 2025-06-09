# 567. Permutation in String
Given two strings s1 and s2, return true if s2 contains a of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false

Constraints:

* 1 <= s1.length, s2.length <= 104
* s1 and s2 consist of lowercase English letters.

## Solution: sliding window

* Use two arrays `count1[]` and `count2[]` to record the number of characters for string s1 and s2.
* As the sliding window moves, update `count2[]`
* Use a variable `matched` to record the number of characters which have the same amount in both s1 and s2. When `matched = 26`, we found a permutation of s1.

