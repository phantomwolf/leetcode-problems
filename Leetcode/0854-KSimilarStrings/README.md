# 854. K-Similar Strings
Strings s1 and s2 are k-similar (for some non-negative integer k) if we can swap the positions of two letters in s1 exactly k times so that the resulting string equals s2.

Given two anagrams s1 and s2, return the smallest k for which s1 and s2 are k-similar.

Example 1:

Input: s1 = "ab", s2 = "ba"
Output: 1
Explanation: The two string are 1-similar because we can use one swap to change s1 to s2: "ab" --> "ba".
Example 2:

Input: s1 = "abc", s2 = "bca"
Output: 2
Explanation: The two strings are 2-similar because we can use two swaps to change s1 to s2: "abc" --> "bac" --> "bca".

Constraints:

* 1 <= s1.length <= 20
* s2.length == s1.length
* s1 and s2 contain only lowercase letters from the set {'a', 'b', 'c', 'd', 'e', 'f'}.
* s2 is an anagram of s1.

## Solution: BFS
Let's see the following example:

    s1 = abbc
    s2 = bbca

When we vertically scan these 2 strings, we'll find s1[0] != s2[0]. To reduce the number of mismatched characters, naturally we want to swap s1[0] with a character 'b' inside s1. However, there're 2 'b' in s1. Which one should we choose? We don't know, but we can try both options:

    abbc -> babc -> bbac -> bbca        // First step: swap s1[0] and s1[1]
      \
        -> bbac -> bbca                 // First step: swap s1[0] and s1[2]

All we need to do is to find the shortest path from s1 "abbc" to s2 "bbca". We can use BFS to solve it.

How do we find all neighbors of a node?

1. Linearly scan s1 until we find the first mismatched char s1[i]
2. Starting from i, find another mismatched character s1[j], which fulfills `s1[j] == s2[i]`. This way, if we swap `s1[i]` and `s1[j]`, because `s1[j] == s2[i]`, we'll reduce a mismatched character, getting closer to the destination(which has 0 mismatched character).
3. Continue `j++` until we've tried all possibilities.
