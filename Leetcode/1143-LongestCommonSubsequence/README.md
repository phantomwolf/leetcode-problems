# 1143. Longest Common Subsequence
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".

A common subsequence of two strings is a subsequence that is common to both strings.

## Example 1

```
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
```

## Example 2

```
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
```

## Example 3

```
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
```

## Constraints

- 1 <= text1.length, text2.length <= 1000
- text1 and text2 consist of only lowercase English characters.

# Solution
## DP Solution
Define dp[i][j] as the length of the longest common subsequence between word1[0,i) and word2[0,j).

Base case: when i or j is 0, the LCS length should be 0.

- When word1[i-1] == word2[j-1], it means word1[i-1]/word2[j-1] definitely should be in the LCS, which also means word1[0,i) and word2[0,j)'s LCS length should be 1 char longer than word1[0,i-1) and word2[0,j-1): dp[i][j] = dp[i-1][j-1] when word1[i-1] == word2[j-1]
- When word1[i-1] != word2[j-1], there're 3 cases
	* word1[i-1] belongs to the LCS, but word2[j-1] doesn't. This means LCS of word1[0,i) and word2[0,j) is the same as the one of word1[0,i) and word2[0,j-1). Aka dp[i][j] = dp[i][j-1]
	* word1[i-1] doesn't belong to the LCS, but word2[j-1] does. This means LCS of word1[0,i) and word2[0,j) is the same as the one of word1[0,i-1) and word2[0,j). Aka dp[i][j] = dp[i-1][j]
	* Neither word1[i-1] nor word2[j-1] belong to the LCS: dp[i][j] = dp[i-1][j-1]. But this case can be ignored since according to dp's definition, dp[i-1][j-1] will never be larger than dp[i-1][j] or dp[i][j-1]

