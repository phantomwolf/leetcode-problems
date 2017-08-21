438 Find All Anagrams in a String 
=====================================================
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1::

    Input:
    s: "cbaebabacd" p: "abc"

    Output:
    [0, 6]

Explanation:

- The substring with start index = 0 is "cba", which is an anagram of "abc".
- The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2::

    Input:
    s: "abab" p: "ab"

    Output:
    [0, 1, 2]

Explanation:

- The substring with start index = 0 is "ab", which is an anagram of "ab".
- The substring with start index = 1 is "ba", which is an anagram of "ab".
- The substring with start index = 2 is "ab", which is an anagram of "ab".


思路
---------------------------
互为变位词(anagram)的两个字符串，长度必定相等，所以我们只要考虑s中所有长度与p相同的子字符串就可以了。

由于字符串中只出现小写字母，所以我们准备两个数组，分别记录s中子字符串和p中字符的数量::

    int p_count[26];
    int s_count[26];

首先扫描字符串p，把字符的数量记录到p_count。然后扫描字符串s中每个长度与p相等的子字符串，记录到s_count中。若对于0 <= i < 26，有p_count[i] == s_count[i]，那么两者互为变位词(anagram)。


优化
---------------------------
首先，没必要每次都从头扫描s中的子字符串，只有第一次需要全部扫描一遍。其他时候，若目前s_count记录了s[i..j]中字符的数量，那么s[i+1..j+1]中的字符数量，可以通过将s[i]从s_count中减去，将s[j+1]加入s_count中来得到。

其次，判断p_count与s_count是否完全相等，也不需要每次都整个扫描一遍。可以设置一个变量count，跟踪p_count与s_count中，有多少个元素相等。若s_count中某个位置更新后，与p_count中对应的元素相等了，那么count++；若s_count中某元素原本与p_count中对应元素相等，更新后不相等了，那么count--。当count = 26时，说明s_count与p_count完全相等，我们就找到了一个anagram。

优化后，时间复杂度为O(n)
