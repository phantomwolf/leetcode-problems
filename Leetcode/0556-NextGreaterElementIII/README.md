# 556. Next Greater Element III
Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

Example 1:

Input: n = 12
Output: 21

Example 2:

Input: n = 21
Output: -1

Constraints:

* 1 <= n <= 2^31 - 1

## Solution: next permutation
Retrieve each digit of the n, and store them in a list. Then it's the same as [Next Permutation](../0031-NextPermutation/README.md).

Be careful of overflows. Use the following condition to detect integer overflow:

```java
    if (num > Integer.MAX_VALUE/10 ||
        (num == Integer.MAX_VALUE/10 && digit > 7)) {
            // Overflow!
    }
```
