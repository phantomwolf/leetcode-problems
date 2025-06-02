# 269. Alien Dictionary
There is a new alien language that uses the English alphabet. However, the order of the letters is unknown to you.

You are given a list of strings words from the alien language's dictionary. Now it is claimed that the strings in words are sorted lexicographically by the rules of this new language.

If this claim is incorrect, and the given arrangement of string in words cannot correspond to any order of letters, return "".

Otherwise, return a string of the unique letters in the new alien language sorted in lexicographically increasing order by the new language's rules. If there are multiple solutions, return any of them.

Example 1:

Input: words = ["wrt","wrf","er","ett","rftt"]
Output: "wertf"
Example 2:

Input: words = ["z","x"]
Output: "zx"
Example 3:

Input: words = ["z","x","z"]
Output: ""
Explanation: The order is invalid, so return "".

Constraints:

* 1 <= words.length <= 100
* 1 <= words[i].length <= 100
* words[i] consists of only lowercase English letters.

## Solution: graph cycle detection
Consider each char as a node in the graph. If char 'a' comes before 'b', create an edge from 'a' to 'b'. This way, if we do topological sort for the graph, the result will be the language rule.

But how should we build the graph? Let's gather insights from examples:

* A single word, such as "wrt", doesn't tell us the lexicographical order(This is the same as English words, such as "bad")
* If word2 is a prefix of word1, but word1 comes before word2, there's no valid order. Return ""
* To find an edge, we can compare two adjacent words character by character, until they're different. For "wrt" and "wrf", 't' comes before 'f', so there's an edge from 't' to 'f'.
* If there's cycle in the graph, the order is invalid and return ""

Algorithm:

1. For each character of each word, let `graph[c] = []byte{}`. This means adding a node in the graph
2. For each two adjacent words `words[i]` and `words[i+1]`, compare each character until they're different, or the index reaches the end of either word.
    a. If `words[i+1]` is a prefix of `words[i]`, index will reach the end of `words[i+1]` first. This means the order is invalid, and the result is "".
    b. If `words[i]` is a prefix of `words[i+1]`, or `words[i] == words[i+1]`, there's no useful info. Skip them.
    c. If `words[i][j] != words[i+1][j]`, there should be an edge from `words[i][j]` to `words[i+1][j]`. Increment the indegree of `words[i+1][j]`.
3. Do topological sort

Building the graph is probably the most challenging part.