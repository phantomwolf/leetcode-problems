# 1871. Jump Game VII
You are given a 0-indexed binary string s and two integers minJump and maxJump. In the beginning, you are standing at index 0, which is equal to '0'. You can move from index i to index j if the following conditions are fulfilled:

    i + minJump <= j <= min(i + maxJump, s.length - 1), and
    s[j] == '0'.

Return true if you can reach index s.length - 1 in s, or false otherwise.

Example 1:

Input: s = "011010", minJump = 2, maxJump = 3
Output: true
Explanation:
In the first step, move from index 0 to index 3. 
In the second step, move from index 3 to index 5.

Example 2:

Input: s = "01101110", minJump = 2, maxJump = 3
Output: false

Constraints:

* 2 <= s.length <= 105
* s[i] is either '0' or '1'.
* s[0] == '0'
* 1 <= minJump <= maxJump < s.length

## Solution 1: naive DP(Time limit exceeded)
Define dp[i] as a bool value which indicates whether we can jump to index i. If all the following conditions are met, dp[i] is true:

* s[i] = '0'
* dp[j] = true, j in range [i-maxJump, i-minJump]

Remember to handle out of range indexes.

Time complexity: O(n^2)
Space complexity: O(n)

## Solution 2: optimized DP
Solution 1 can be optimized using sliding window technique: the inner loop is just looking for `dp[j] == true`, j in range `[i-maxJump, i-minJump]`. Since i moves 1 step each time, `[i-maxJump, i-minJump]` is a sliding window. We can use a variable `count` to track the number of dp[j] == true in the window.

Time complexity: O(n)
Space complexity: O(n)