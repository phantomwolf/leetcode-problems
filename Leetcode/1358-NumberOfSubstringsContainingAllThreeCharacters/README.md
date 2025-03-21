# 1358. Number of Substrings Containing All Three Characters
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 

Example 3:

Input: s = "abc"
Output: 1

Constraints:

* 3 <= s.length <= 5 x 10^4
* s only consists of a, b or c characters.

## Solution: sliding window
We can solve it using the sliding window technique. For sliding window [i, j), let count[] contain the number of 'a', 'b', 'c' and variable "matched" to track how many characters in 'a', 'b', 'c' has at least 1 in the sliding window. When matched == 3, it means in the current sliding window, we have at least 1 of each of 'a', 'b', 'c'.

Algorithm:

    at the beginning, i = 0, j = 0
    when expanding/shrinking the sliding window, if character c is one of 'a', 'b', 'c', we record its amount using count[c].
    expand sliding window by incrementing j until it reaches the end or matched == 3. After this, [i, j) will be a valid sliding window which has at least 1 of each of 'a', 'b', 'c'
    shirk sliding window by incrementing i until the sliding window no longer fulfills the requirements(meanwhile remember to collect results)
    