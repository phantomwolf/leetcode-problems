# 10. Regular Expression Matching
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Constraints:

* 1 <= s.length <= 20
* 1 <= p.length <= 20
* s contains only lowercase English letters.
* p contains only lowercase English letters, '.', and '*'.
* It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.

## Solution 1: define subproblem as suffix
Define `dp(String s, int i, String p, int j)` as whether s[i...] and p[j...] matches. A subproblem will be like `dp(s, i+1, p, j+1)`. We can see the subproblem is a suffix string. Defining subproblems as suffix makes the code a bit cleaner. 

### Solution a: recursion + memo = dynamic programming
Define recursive function `dp(String s, int i, String p, int j)` as whether s[i...] and p[j...] matches.

Base cases:

1. If `j == p.length()`, we've exhausted the pattern `p`. If we also exhausted the string `i == s.length()`, it means they match; otherwise, they don't match.
2. If `i == s.length()`, it's a bit complicated:
    a. If `j == p.length()`, it's same as case 1.
    b. If `j < p.length()`, there's still a chance that they can match. If the rest of the pattern is like "x*y*z*", we can let them match 0 characters, so that string and pattern will match. Otherwise, return false.

Optimal substructure:

```java
if (s.charAt(i) == p.charAt(j) || p.charAt(j) == '.') {
    // s[i] and p[j] matches. Now check if p[j+1] is '*'
    if (j+1 < p.length() && p.charAt(j+1) == '*') {
        // case 1: 'x*' matches 0 characters. (x means any character)
        boolean cand1 = dp(s, i, p, j+2);
        // case 2: * matches 1 or more characters(j didn't increment because 'x*' can be used again until it matches 0 characters)
        boolean cand2 = dp(s, i+1, p, j);
        return cand1 || cand2;
    } else {
        // p[j+1] is not '*'. Just do a simple 1 character match.
        return dp(s, i+1, p, j+1);
    }
} else {
    // s[i] and p[j] doesn't match. The only hope of matching is p[j+1] is '*', so that it can match 0 characters.
    if (j+1 < p.length() && p.charAt(j+1) == '*') {
        return dp(s, i, p, j+2);
    }
    // p[j+1] is not '*'. No hope of matching.
    return false;
}
```

Now add a memo to make it dynamic programming:

```java
// Define memo values:
//      -1: not set
//      0:  false
//      1:  true
int[][] memo = new int[s.length()][p.length()];
for (int[] arr : memo) {
    Arrays.fill(arr, -1);
}
```

### Solution b: bottom up dynamic programming
Define dp[i][j] as whether s[i...] and p[j...] matches: `boolean[][] dp = new boolean[s.length()+1][p.length()+1];`.

Base case:

* When both string and pattern are empty, it's a match: `dp[s.length()][p.length()] = true`.

Optimal substructure:

* If s[i] and p[j] matches, aka `s[i] == p[j]` or `p[j] == '.'`:
    - If `p[j+1] == '*'`, `"p[j]*"` can either match 0 characters, or 1 or more characters.
    - If `j+1` out of index, or `p[j+1] != '*'`, do a simple 1 character match.
* If s[i] and p[j] don't match, the only hope of match is when p[j+1] is '*', so that "p[j]*" can match 0 characters.
