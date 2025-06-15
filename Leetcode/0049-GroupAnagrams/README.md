# 49. Group Anagrams
Given an array of strings strs, group the

together. You can return the answer in any order.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

* There is no string in strs that can be rearranged to form "bat".
* The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
* The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

Example 2:

Input: strs = [""]

Output: [[""]]

Example 3:

Input: strs = ["a"]

Output: [["a"]]

 

Constraints:

* 1 <= strs.length <= 104
* 0 <= strs[i].length <= 100
* strs[i] consists of lowercase English letters.


## Solution 1: count
To group anagrams, the straightforward way is to hash each string into a key of a hash map.

Since string can be used as key, we can convert each input string into a unique string key: length 26, each character is the count of an English letter. For example, key[0] is the count of 'a', and key[1] is the count of 'b'. Apparently, this unique string key is probably not printable, but this doesn't affect the program.