# 7. Reverse Integer
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21

Constraints:

* -2^31 <= x <= 2^31 - 1

## Solution
In most programming languages(except Python, Ruby), we can get the last digit of `x` by `digit = x % 10`. Then we let `x /= 10`, so that we can get the next digit.

For each digit, we can do `newResult = result * 10 + digit`.

### Overflow Detection 1
For `result > 0`, if `newResult = result * 10 + digit > INT_MAX`, which is equivalent to `result > (INT_MAX - digit)/10`.

For `result < 0`, if `newResult = result * 10 + digit < INT_MIN`, which is equivalent to `result < (INT_MIN - digit)/10`.

Conclusion:

```java
    if (res > 0 && res > (Integer.MAX_VALUE - digit)/10) {
        return 0;
    } else if (res < 0 && res < (Integer.MIN_VALUE - digit)/10) {
        return 0;
    }
```

### Overflow Detection 2
For 32-bit int, INT_MAX is 2147483647 and INT_MIN is -2147483648. To detect overflow, we have to detect before actually doing the calculation.

For `result > 0`, if `newResult = result * 10 + digit > INT_MAX`, it means either `result > 214748364` or `result == 214748364 && digit > 7`. Note: `INT_MAX / 10 == 214748364`.

For `result < 0`, if `newResult = result * 10 + digit < INT_MIN`, it means either `result < -214748364` or `result == -214748364 && digit < -8`. Note: `INT_MIN / 10 == -214748364`.

Conclusion:

```java
    if (res > Integer.MAX_VALUE / 10 ||
        (res == Integer.MAX_VALUE && digit > 7)) {
            return 0;
    }
    if (res < Integer.MIN_VALUE / 10 ||
        (res == Integer.MIN_VALUE / 10 && digit < -8)) {
                return 0;
    }
```
