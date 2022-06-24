# 139. Word Break

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

## Example 1

```
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
```

## Example 2

```
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
```

## Example 3

```
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
```

## Constraints

- 1 <= s.length <= 300
- 1 <= wordDict.length <= 1000
- 1 <= wordDict[i].length <= 20
- s and wordDict[i] consist of only lowercase English letters.
- All the strings of wordDict are unique.

## 最优子结构
当遇到特定的输入时，最优子结构是存在的。比如对于输入xxxxxxapplepen，wordDict = ["x","apple", "pen", "applepen"]，既可以分词为x|x|x|x|x|x|apple|pen，又可以x|x|x|x|x|x|applepen。把之前xxxxxx分词结果存下来，就可以重用。

## Solution: DP with Trie
观察DP Solution，在内循环里，我们需要获取每一个substring s[j, i)，并查询它在Set中是否存在。有了Trie的帮助，我们可以把这一过程的时间复杂度从O(n^2)降低到O(n)。

对于这些substring，它们并不从同一个字符开始，但都从同一个字符s.charAt(i - 1)结束。我们可以将所有word反转并存入Trie，这样我们就可以从s.charAt(i - 1)开始，向前搜索Trie。
