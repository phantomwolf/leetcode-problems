# 1249. Minimum Remove to Make Valid Parentheses
Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

    It is the empty string, contains only lowercase characters, or
    It can be written as AB (A concatenated with B), where A and B are valid strings, or
    It can be written as (A), where A is a valid string.

Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"

Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.

Constraints:

* 1 <= s.length <= 105
* s[i] is either '(' , ')', or lowercase English letter.

## Solution 1: stack
Stack is a pretty common tool for solving parentheses matching problems:

* When meeting "(", push the index into stack
* When meeting ")", pop stack. If stack is empty when popping, it means we have extra ")"
* If stack isn't empty after scanning the string, it means we have extra "(".

Add the indexes of non-matching parentheses into a hash set, and ignore these indexes when building the result using StringBuilder.

## Solution 2: two pass solution(no stack)
It's often very common to use a single variable to track the matching parentheses:

* When meeting "(", let balance++
* When meeting ")", let balance--. If balance is already 0, it means we met an extra ")"
* After done scanning, if balance > 0, it means we had extra "(" in the string. To get a balanced string, simply remove some rightmost "("

