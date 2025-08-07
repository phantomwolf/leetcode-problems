# Backtracking
Backtracking algorithms are like problem-solving strategies that help explore different options to find the best solution. They work by trying out different paths and if one doesn't work, they backtrack and try another until they find the right one. It's like solving a puzzle by testing different pieces until they fit together perfectly.

## Explanation
Backtracking is like traversing a multi-branch tree.

## Recursive pseudocode

```
void backtrack()
    if path is complete:
        add path to result
    for choice in choice_list:
        make a choice/one step forward
        recursively call backtrack()
        cancel the choice/one step back
```


# Leetcode Problems

* [17. Letter Combinations of a Phone Number](../../Leetcode/0017-LetterCombinationsOfAPhoneNumber/README.rst)
* [39. Combination Sum](https://leetcode.com/problems/combination-sum/)
* [40. Combination Sum II](https://leetcode.com/problems/combination-sum-ii/description/)
* [216. Combination Sum III](https://leetcode.com/problems/combination-sum-iii/description/)

