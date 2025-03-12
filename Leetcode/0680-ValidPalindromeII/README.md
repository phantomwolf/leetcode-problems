# 680. Valid Palindrome II
Given a string s, return true if the s can be palindrome after deleting at most one character from it.

Example 1:

Input: s = "aba"
Output: true

Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.

Example 3:

Input: s = "abc"
Output: false

Constraints:

* 1 <= s.length <= 105
* s consists of lowercase English letters.

## Solution: two pointers
The algorithm to verify ordinary palindrome: use 2 pointers i and j from both sides and move towards the middle, comparing characters one by one.

However, this problem allows us to delete 1 character at most. When 2 characters mismatch, we face two options:

1. Delete **s[i]** and continue verifying the remaining part of **s**
2. Delete **s[j]** and continue verifying the remaining part of **s**

There's no way to tell which option is correct until we actually verify them. So let's write a helper function for verifying palindrome strings which allows specifiying the range:

```java
class Solution {
    public boolean validPalindrome(String s) {
        return isPalindrome(s, 0, s.length()-1, 1);
    }

    private boolean isPalindrome(String s, int l, int r, int credit) {
        while (l < r) {
            if (s.charAt(l) == s.charAt(r)) {
                l++;
                r--;
                continue;
            }
            // If two characters mismatch
            if (credit <= 0) {
                // We can no longer delete characters
                return false;
            }
            // Consume 1 credit to delete 1 character
            credit--;
            // If either option returns true, the overall result is true
            return isPalindrome(s, l+1, r, credit) || isPalindrome(s, l, r-1, credit);
        }
        return true;
    }
}
```

Note: credit means how many times we can delete.