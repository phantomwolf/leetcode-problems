# 2262. Total Appeal of A String
The appeal of a string is the number of distinct characters found in the string.

    For example, the appeal of "abbca" is 3 because it has 3 distinct characters: 'a', 'b', and 'c'.

Given a string s, return the total appeal of all of its substrings.

A substring is a contiguous sequence of characters within a string.

Example 1:

    Input: s = "abbca"
    Output: 28

Explanation: The following are the substrings of "abbca":
- Substrings of length 1: "a", "b", "b", "c", "a" have an appeal of 1, 1, 1, 1, and 1 respectively. The sum is 5.
- Substrings of length 2: "ab", "bb", "bc", "ca" have an appeal of 2, 1, 2, and 2 respectively. The sum is 7.
- Substrings of length 3: "abb", "bbc", "bca" have an appeal of 2, 2, and 3 respectively. The sum is 7.
- Substrings of length 4: "abbc", "bbca" have an appeal of 3 and 3 respectively. The sum is 6.
- Substrings of length 5: "abbca" has an appeal of 3. The sum is 3.
The total sum is 5 + 7 + 7 + 6 + 3 = 28.

Example 2:

    Input: s = "code"
    Output: 20

Explanation: The following are the substrings of "code":
- Substrings of length 1: "c", "o", "d", "e" have an appeal of 1, 1, 1, and 1 respectively. The sum is 4.
- Substrings of length 2: "co", "od", "de" have an appeal of 2, 2, and 2 respectively. The sum is 6.
- Substrings of length 3: "cod", "ode" have an appeal of 3 and 3 respectively. The sum is 6.
- Substrings of length 4: "code" has an appeal of 4. The sum is 4.
The total sum is 4 + 6 + 6 + 4 = 20.

Constraints:

* 1 <= s.length <= 105
* s consists of lowercase English letters.

## Solution 1: count each character separately
我们可以分别计算每个字符。

对于输入`axxaxxb`，以b结尾的子字符串中，有多少个含有a的字符串呢？答案是axxaxxb, xxaxxb, xaxxb, axxb。这4个子字符串的unique characters里均包含a，a字符为最后答案贡献了4。依次对所有字符进行此操作，就能知道所有以b结尾的所有子字符串里，共有多少个unique characters。

依次以每个字符做结尾，把结果累加起来，就能得到最终结果。

Time complexity: O(N); Space complexity: O(26N)

## Solution 3:
以长度为6的输入`xaxaxb`为例，当子字符串包含1个a时，a算作一个unique字符，例如xaxb；当子字符串包含2个a时，2个a只计算一次，例如xaxaxb。我们不妨规定，当一个字符出现多次时，我们只计算第一个。

那么s[1] = 'a'在最终结果里一共被计算了几次呢？由于s[1]是整个字符串中的第一个a，根据我们的规定，任何包含了s[1]的子字符串中，s[1]都会被计算一次。那么包含s[1]的子字符串一共有多少呢？我们从[0,1]中任选一个字符作为子字符串的起点，再从[1, 5]中任选一个字符作终点，都能得到一个包含s[1] = 'a'的唯一子字符串，因此共有2 x 4 = 8个，即s[1]为最终结果贡献了8。

再来看第二个s[3] = 'a'被计算了几次。根据我们的规定，如果s[1]也包含在子字符串中，那么s[3]不会被计算在内。因此当且仅当s[3]是子字符串中的第一个a字符时，即子字符串包含s[3]且不包含它的上一个s[1] = 'a'时，它才会被计算一次。这样的字符串总共有多少呢？从[2, 3]中任选一个字符做起点，[3, 5]中任选一个字符做终点，都能得到一个包含s[3] = 'a'的唯一子字符串，因此共有2 x 2 = 4个，即s[3]为最终结果贡献了4。

因此我们完全可以遍历字符串，计算每个字符的贡献，结果的总和就是我们要的结果。

# Similar problem

* [828. Count Unique Characters of All Substrings of a Given String](https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/)
