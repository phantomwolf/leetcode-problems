# 127. Word Ladder
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words `beginWord -> s1 -> s2 -> ... -> sk` such that:

* Every adjacent pair of words differs by a single letter.
* Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
* sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

Constraints:

* 1 <= beginWord.length <= 10
* endWord.length == beginWord.length
* 1 <= wordList.length <= 5000
* wordList[i].length == beginWord.length
* beginWord, endWord, and wordList[i] consist of lowercase English letters.
* beginWord != endWord
* All the words in wordList are unique.

## Solution 1: naive BFS
If we consider each word as a node in a graph, this problem is asking us to calculate the shortest distance from beginWord to endWord. If two words differ by only a single letter, there's an edge between them.

How can we find all adjacent neighboring nodes of a word? A naive solution is to iterate wordList and compare them one by one. Then the rest of the solution is just regular BFS.

## Solution 2: preprocessing + BFS
How do we quickly find the neighboring nodes of a word? This can be done by preprocessing.

For example, from word "hot", its neighboring nodes are "dot", "lot". If we use a '*' to replace each character of "hot", we can get the following three words:

1. *ot
2. h*t
3. ho*

If any other word can generate the same preprocessed word, it means these two words are adjacent. For example, "dot" can generate the following words:

1. *ot
2. d*t
3. do*

We can see both "hot" and "dot" can generate "*ot", which means these two words differ by a single letter.

To quickly find adjacent nodes, we build a map from preprocessed words to a list of original words. Any two words in the same list are adjacent. With this preprocessing, we can find neighboring nodes with O(1) time complexity.

