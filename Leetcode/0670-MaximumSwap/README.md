# 670. Maximum Swap
You are given an integer num. You can swap two digits at most once to get the maximum valued number.

Return the maximum valued number you can get.

Example 1:

Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.

Example 2:

Input: num = 9973
Output: 9973
Explanation: No swap.

Constraints:

* 0 <= num <= 108

## Solution
For num = 2736, we scan the number from right to left, each time extracting 1 digit.

The 1st digit is 6. There's no digit on its right side.

The 2nd digit is 3. The greatest digit on its right side is 6. We can make a swap to make the number greater: 2763.

The 3rd digit is 7. The greatest digit on its right side is 6. No swap can be made.

The 4th digit is 2. The greatest digit on its right side is 7. We can make a swap to make the number greater: 7236.

So to solve this problem, we need to scan each digit from right to left. During this process, we use a variable to track the greatest digit scanned so far, and record its position.