Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1

Clarification:
What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().


01234567
AAACAAAA
01201233

当i=7时，len=3(上一轮循环里，符合条件的前缀为AAA)，pat[len] = 'C' != 'A' = pat[i]。此时，令len = lps[len-1]，即lps[2]，i不变。
