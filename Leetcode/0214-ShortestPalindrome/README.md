# 214. Shortest Palindrome
You are given a string s. You can convert s to a palindrome by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.

## Example 1

```
Input: s = "aacecaaa"
Output: "aaacecaaa"
```

## Example 2

```
Input: s = "abcd"
Output: "dcbabcd"
```

## Constraints:

- 0 <= s.length <= 5 * 104
- s consists of lowercase English letters only.

# Solution
Note that you're allowed to add characters only at the beginning.

If we can find the longest palindrome substring which starts from the beginning of s, all we need to do next is adding the remaining characters to the beginning. Example:

	"aacecaaa" has a palindrome substring "aacecaa" which starts from the beginning. After this, we just need to add the remaining part "a" to the beginning of it

But how do we quickly find such a palindrome? If we reverse "s" to "r", such a palindrome substring will be both a prefix of "s", and a suffix of "r". If we concatenate "s" and "r", such a palindrome substring will be both the prefix and suffix of the concatenation. This means we can use the lps[] array from KMP algorithm.
