# 2259. Remove Digit From Number to Maximize Result
You are given a string number representing a positive integer and a character digit.

Return the resulting string after removing exactly one occurrence of digit from number such that the value of the resulting string in decimal form is maximized. The test cases are generated such that digit occurs at least once in number.

Constraints:

- 2 <= number.length <= 100
- number consists of digits from '1' to '9'.
- digit is a digit from '1' to '9'.
- digit occurs at least once in number.

## Example 1

```
Input: number = "123", digit = "3"
Output: "12"
Explanation: There is only one '3' in "123". After removing '3', the result is "12".
```

## Example 2

```
Input: number = "1231", digit = "1"
Output: "231"
Explanation: We can remove the first '1' to get "231" or remove the second '1' to get "123".
Since 231 > 123, we return "231".
```

## Example 3

```
Input: number = "551", digit = "5"
Output: "51"
Explanation: We can remove either the first or second '5' from "551".
Both result in the string "51".
```

## Analysis
See the following example: input is "1325353", and digit to be removed is '3'.

| Which '3' to remove | 1 | 2 | 3 | 4 | 5 | 6 |
-----------------------------------------------
| 1st                 | 1 | 2 | 5 | 3 | 5 | 3 |
| 2nd                 | 1 | 3 | 2 | 5 | 5 | 3 |
| 3rd                 | 1 | 3 | 2 | 5 | 3 | 5 |

The 1st '3' has an index of 1. If we delete the 1st '3', the 2nd most significant digit will be '2', which is the one after '3'; if we delete '3' after the 1st one, the 2nd most significant digit will be '3'. This is where it makes a difference.

Suppose the digit to be removed is **X**. Whenever we find an **X** to be removed in the input, just compare it with the digit after it(if available): If the digit after **X** is greater, delete this **X**, so that the digit after **X** will take over the position; otherwise, don't delete it so that **X** will take over the position. If we can't find such an **X**, delete the last **X**.

After figuring out which **X** should be deleted, we can get the result.
