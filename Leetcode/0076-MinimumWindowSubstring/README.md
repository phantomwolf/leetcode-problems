# 76. Minimum Window Substring
Given two strings `s` and `t` of lengths `m` and `n` respectively, return the minimum window of `s` such that every character in `t` (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

Constraints:

* m == s.length
* n == t.length
* 1 <= m, n <= 105
* s and t consist of uppercase and lowercase English letters.

Follow up: Could you find an algorithm that runs in O(m + n) time?

## Analysis
The problem asks us to find a substring of `s`, such that `s` includes every character in `t`(including duplicates). The shorter, the better. This means the result should have the following characteristics:

* The length of `s` must be no smaller than `t`. Otherwise, it's impossible to find such a substring.
* `result.length >= t.length`
* If char `a` occurs `x` times in `t`, it must occur `x` or more times in `result`.
* It's ok if char `a` occurs more times in `s` than it does in `t`.

## Solution: sliding window
Based on the analysis, we can use the **hash map + variable** technique to check if a sliding window contains all characters in `t`:

* Use a hash map/array to record the number of each character in `t`: countT[128]
* Use the same thing to record the number of each character in the sliding window: countS[128]
* Use a variable `unmatched` to track the number of characters that doesn't match between the sliding window and `t`.
    - At the beginning, any unique char in `t` should be considered as unmatched.
    - When the window slides, whenever `countS[c] < countT[c]`, it's considered as unmatched.
* If a char doesn't exist in `t`, it's irrelevant. Even if it exists in the sliding window, we should ignore it: don't record its amount; don't change `unmatched`; just increment the index.
