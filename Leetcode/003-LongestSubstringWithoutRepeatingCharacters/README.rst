3.Longest Substring Without Repeating Characters
================================================================
Given a string, find the length of the longest substring without repeating characters.

Examples:

- Given "abcabcbb", the answer is "abc", which the length is 3.
- Given "bbbbb", the answer is "b", with the length of 1.
- Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

1.Brute Force [Time Limit Exceeded] 
-------------------------------------------
Intuition: Check all the substring one by one to see if it has no duplicate character.

Time complexity: O(n^3)

Space complexity: O(min(n,m)). We need O(k) space for checking a substring has no duplicate characters, where k is the size of the Set. The size of the Set is upper bounded by the size of the string n and the size of the charset/alphabet m. 

2.Sliding Window [Accepted]
-------------------------------------------
用一个set来记录目前为止出现的字符。顺序扫描字符串s，每次都把当前字符加入到set中，直到出现重复字符为止。这时，我们就得到了一个可能的答案。用一个变量来跟踪结果的长度，每次取较长的结果。

接下来，我们计算下一个可能的答案。目前，加入下一个字符会导致重复字符的出现，因此我们不断从当前结果的左边移除字符，直到加入下一个字符也不会引起重复为止。接着，我们不断在右边加入字符，直到会导致重复为止。这样，就得到了另一个可能的答案。

由于我们用一个变量跟踪结果的长度，因此最后结束后，变量存放的就是最长的结果。

Time complexity : O(2n). In the worst case each character will be visited twice by i and j.

Space complexity : O(min(m,n)). Same as the previous approach. We need O(k) space for the sliding window, where k is the size of the Set. The size of the Set is upper bounded by the size of the string n and the size of the charset/alphabet m.

3.Sliding Window Optimized [Accepted]
-------------------------------------------
基本思路与上述算法相同，也是遍历字符串。我们设置一个map结构，记录字符最近一次出现的位置。这次我们不再靠字符是否在hash里来判断该字符是否在当前结果中，而是通过一个字符出现的位置与当前结果的范围对比，来判断字符是否在当前结果中。

意思就是，我们不需要从左边一个个删除字符了。若当要加入一个新字符c时会引起重复，我们只需查询map，找出该字符上一次出现的位置，然后让当前结果的左边界跳过那个位置即可。

Complexity Analysis
Time complexity : O(n). Index j will iterate n times.
Space complexity (HashMap) : O(min(m,n)). Same as the previous approach.
Space complexity (Table): O(m). m is the size of the charset.
