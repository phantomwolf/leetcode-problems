# 828. Count Unique Characters of All Substrings of a Given String
Let's define a function countUniqueChars(s) that returns the number of unique characters on s.

    For example, calling countUniqueChars(s) if s = "LEETCODE" then "L", "T", "C", "O", "D" are the unique characters since they appear only once in s, therefore countUniqueChars(s) = 5.

Given a string s, return the sum of countUniqueChars(t) where t is a substring of s. The test cases are generated such that the answer fits in a 32-bit integer.

Notice that some substrings can be repeated so in this case you have to count the repeated ones too.

Example 1:

    Input: s = "ABC"
    Output: 10
    Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
    Every substring is composed with only unique letters.
    Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10

Example 2:

    Input: s = "ABA"
    Output: 8
    Explanation: The same as example 1, except countUniqueChars("ABA") = 1.

Example 3:

    Input: s = "LEETCODE"
    Output: 92

Constraints:

* 1 <= s.length <= 105
* s consists of uppercase English letters only.

## Solution
可知，当一个字符只出现了一次时，它将被记入结果；如果出现了2次或以上，它将不会被计入结果。

以长度为8的输入xaxaxaxb为例，思考对于什么样的子字符串，s[3] = 'a'会被计算在内？答案是当子字符串包含s[3]，且不包含s[1]和s[5]时，共4个：xax, xa, ax, a。计算方法：从[2, 3]中任选一个字符作为起点，从[3, 4]中任选一个字符作为终点，2 x 2 = 4。

对于s[1] = 'a'，由于前面没有a，所以应该从[0, 1]中选一个起点，[1, 2]中选一个终点。即s[1] = 'a'对最终结果的贡献为：2 x 2 = 4。对于s[5] = 'a'，由于后面没有a，所以应该从[4, 5]中选一个起点，[5, 7]中选一个终点。即s[5] = 'a'对最终结果的贡献为：2 x 3 = 6。

对于此算法，我们需要快速找出某个字符的前一个和后一个相同字符。可以用一个二维数组last2，保存每个字符最近两次出现的位置，在遇到第三个时（或到达结尾时），用上述公式计算结果。

## Similar Problem
* 2262: Total Appeal of a String
