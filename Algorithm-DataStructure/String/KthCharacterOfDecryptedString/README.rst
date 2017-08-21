Find k’th character of decrypted string
=========================================================
Given an encoded string where repetitions of substrings are represented as substring followed by count of substrings. For example, if encrypted string is “ab2cd2” and k=4 , so output will be ‘b’ because decrypted string is “ababcdcd” and 4th character is ‘b’.

Note: Frequency of encrypted substring can be of more than one digit. For example, in “ab12c3”, ab is repeated 12 times. No leading 0 is present in frequency of substring.

Examples:

Input: "a2b2c3", k = 5
Output: c
Decrypted string is "aabbccc"

Input : "ab4c2ed3", k = 9
Output : c
Decrypted string is "ababababccededed"

Input: "ab4c12ed3", k = 21
Output: e
Decrypted string is "ababababccccccccccccededed"

Recommended: Please try your approach on {IDE} first, before moving on to the solution.

The idea is simple. Initially take empty decrypted string then decompress the string by reading substring and it’s frequency one by one and append current substring in decrypted string by it’s frequency. Repeat the process till the end of string and print the K’th character from decrypted string.
