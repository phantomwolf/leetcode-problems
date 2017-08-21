30.Substring with Concatenation of All Words 
===================================================
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters. 

For example, given::

    s1: "barfooqfoobarman"
    words1: ["foo", "bar"]

You should return the indices: [0, 7]. Another example::

    s2: "barfoobar"
    words2: ["foo", "bar"]

You should return the indices: [0, 3].

O(mn)算法
-----------------------------------------
m为words中每个词的长度，n为字符串s的长度。以题目中的例子来讲，我们可以将foo和bar各自视为一个单独的“字符”(可用其hash值表示)。s1中，位置0出现了字符"bar"，紧接着位置3出现了字符"foo"，此时已出现了words1中的所有词，我们得到了一个结果。之后，我们看接下来的“字符”qfo、oba、rma，均未在words1中出现。

第二轮循环，我们不从位置0开始，而是从位置1开始，扫描到的“字符”依次为arf、ooq、foo、bar、man，扫描完bar以后，所有词都已经出现过，我们得到一个结果。

接下来再次更改开始位置，开始新一轮扫描。

如何判断words中的词全部出现过了？
++++++++++++++++++++++++++++++++++++
可以设置一个map1，统计words中每个词出现的数量，键为words中的词，值为其出现的次数。

扫描字符串s时，再为当前扫描的部分设置另一个map2，统计当前扫描的部分中，每个词出现了几次，并用一个变量count统计共出现了几个有效的词(所谓有效词，就是出现次数仍为超过map1中次数的词。)

如何判断一个词存在于words中？
++++++++++++++++++++++++++++++++++++
可以设置一个map1，统计words中每个词出现的数量，键为words中的词，值为其出现的次数。只要一个词的出现次数不为0，那就是存在。
