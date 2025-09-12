# 869. Reordered Power of 2
You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this so that the resulting number is a power of two.

Example 1:

Input: n = 1
Output: true
Example 2:

Input: n = 10
Output: false

Constraints:

* 1 <= n <= 109

## Solution
This problem is the same as finding anagrams of a string, except that the input is an integer. The solution is similar: first calculate all popwer of 2, and count the number of each digit, then compare with the input. If the input number has the same amount of digits as a certain power of 2 number, it means we can reorder the digits to make it a power of 2.

**Overflow**: since we're dealing with integers, remember to check for overlows.