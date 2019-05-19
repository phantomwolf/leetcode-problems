# 1048. Longest String Chain
Given a list of words, each word consists of English lowercase letters.

Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2.  For example, "abc" is a predecessor of "abac".

A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.

Return the longest possible length of a word chain with words chosen from the given list of words.

 

Example 1:

Input: ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: one of the longest word chain is "a","ba","bda","bdca".

 

Note:

    1 <= words.length <= 1000
    1 <= words[i].length <= 16
    words[i] only consists of English lowercase letters.

## 解答
可以用动态规划来解决。

在此之前，题目并没有说word_2必须出现在word_1之前，因此我们要将数组按照每个字符串的长度来排序，这样一个元素的predecessor必定在其左边，简化了问题。

设d[i]表示：在只能使用words[0]..words[i]，且words[i]被使用的情况下，所能组成的chain的最大长度。可知，d[i]的最小值为1(当words[i]的左边没有任何predecessor时，chain中之有words[i]本身，因此chain长度为1)。若words[j]为words[i]的predecessor(j < i)，那么d[i]一个可能的取值就是d[j] + 1。

在Example 1中，d[0] = 1；因words[0]和words[1]均为words[2]的predecessor，因此d[2] = max(d[0] + 1, d[1] + 1) = 2；words[3]在左边的predecessor之有words[2]，因此d[3] = d[2] + 1 = 3。
