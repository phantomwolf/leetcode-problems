Summary
=============================================================
We need to determine the length of the largest valid substring of parentheses from a given string.


Approach #1 Brute Force [Time Limit Exceeded]
---------------------------------------------------
Algorithm
+++++++++++++++++++++++++++++++++++++++
In this approach, we consider every possible non-empty even length substring from the given string and check whether it's a valid string of parentheses or not. In order to check the validity, we use the Stack's Method.

Every time we encounter a '(', we push it onto the stack. For every ')' encountered, we pop a '(' from the stack. If '(' isn't available on the stack for popping at anytime or if stack contains some elements after processing complete substring, the substring of parentheses is invalid. In this way, we repeat the process for every possible substring and we keep on storing the length of the longest valid string found so far.

Example::

    "((())"
    
    (( --> invalid
    (( --> invalid
    () --> valid, length=2
    )) --> invalid
    ((()--> invalid
    (())--> valid, length=4
    maxlength=4

Complexity Analysis
+++++++++++++++++++++++++++++++++++++++
Time complexity : O(n^3). Generating every possible substring from a string of length n requires O(n^2). Checking validity of a string of length nnn requires O(n).

Space complexity : O(n). A stack of depth n will be required for the longest substring.


Approach #2 Using Dynamic Programming [Accepted]
---------------------------------------------------
Algorithm
+++++++++++++++++++++++++++++++++++++++
This problem can be solved by using Dynamic Programming. We make use of a dp array where ith element of dp represents the length of the longest valid substring ending at ith index. We initialize the complete dp array with 0's. Now, it's obvious that the valid substrings must end with ')'. This further leads to the conclusion that the substrings ending with '(' will always contain '0' at their corresponding dp indices. Thus, we update the dp array only when ')' is encountered.

dp array we will check every two consecutive characters of the string and if

case1: s[i] == ')' and s[i-1] == '(', i.e. string looks like ".....()", then dp[i] = dp[i-2] + 2.

We do so because the ending "()" portion is a valid substring anyhow and leads to an increment of 2 in the length of the just previous valid substring's length.

case2: s[i]=')' and s[i−1]=')', i.e. string looks like ".......))". If s[i−dp[i−1]−1]='(' then dp[i]=dp[i−1]+dp[i−dp[i−1]−2]+2. 

Complexity Analysis
+++++++++++++++++++++++++++++++++++++++
- Time complexity : O(n). Single traversal of string to fill dp array is done.
- Space complexity : O(n). dp array of size n is used.


Approach #3 Using Stack [Accepted]
---------------------------------------------------
Algorithm
+++++++++++++++++++++++++++++++++++++++
Instead of finding every possible string and checking its validity, we can make use of stack while scanning the given string to check if the string scanned so far is valid, and also the length of the longest valid string. In order to do so, we start by pushing −1 onto the stack.

For every '(' encountered, we push its index onto the stack.

For every ')' encountered, we pop the topmost element and subtract the current element's index from the top element of the stack, which gives the length of the currently encountered valid string of parentheses. If while popping the element, the stack becomes empty, we push the current element's index onto the stack. In this way, we keep on calculating the lengths of the valid substrings, and return the length of the longest valid string at the end.

我的理解
+++++++++++++++++++++++++++++++++++++++
我们知道，用栈可以验证一个字符串里的括号是否匹配。例如，"()(())"，'('入栈，')'出栈，扫描结束时栈为空，这表示括号匹配成功。

但本问题需要找出最长的子字符串，要求其括号匹配。这意味着，整个字符串本身的括号可能并不完全匹配，例如"(()"。

本算法做了如下修改：

- 入栈的是相应字符的下标
- 永远在栈的最底层保存一个下标，这个下标表示有效子字符串开头的前一个位置，方便我们计算有效子字符串的长度



Complexity Analysis
+++++++++++++++++++++++++++++++++++++++
- Time complexity : O(n)O(n)O(n). nnn is the length of the given string..
- Space complexity : O(n)O(n)O(n). The size of stack can go up to nnn.


Approach #4 Without extra space [Accepted]
---------------------------------------------------
Algorithm
+++++++++++++++++++++++++++++++++++++++
In this approach, we make use of two counters left and right. First, we start traversing the string from the left towards the right and for every '(' encountered, we increment the left counter and for every ')' encountered, we increment the right counter. Whenever left becomes equal to right, we calculate the length of the current valid string and keep track of maximum length substring found so far. If right becomes greater than left we reset left and right to 0.

Next, we start traversing the string from right to left and similar procedure is applied.

受到上一个算法启发，我们其实没必要使用栈，只需要记录左括号和右括号的数量，以及当前有效子字符串的起点即可。


Complexity Analysis
+++++++++++++++++++++++++++++++++++++++
- Time complexity : O(n). Two traversals of the string.
- Space complexity : O(1). Only two extra variables left and right are needed.
