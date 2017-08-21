Nesting
============================================
Determine whether given string of parentheses is properly nested. 


Description
-------------------------------
A string S consisting of N characters is called properly nested if::

    S is empty;
    S has the form "(U)" where U is a properly nested string;
    S has the form "VW" where V and W are properly nested strings.

For example, string "(()(())())" is properly nested but string "())" isn't.

Write a function::

    int solution(string &S);

that, given a string S consisting of N characters, returns 1 if string S is properly nested and 0 otherwise.

For example, given S = "(()(())())", the function should return 1 and given S = "())", the function should return 0, as explained above.

Assume that::

        N is an integer within the range [0..1,000,000];
        string S consists only of the characters "(" and/or ")".

Complexity::

        expected worst-case time complexity is O(N);
        expected worst-case space complexity is O(1) (not counting the storage required for input arguments).


思路
-------------------------------
解法与之前的Brackets问题相同，可以用栈来存储左括号们，遇到右括号就试图弹出栈中的左括号。但是本题要求O(1)的空间复杂度。

仔细观察发现，字符串中只有一种左括号"("，也就是说，我们没必要真的把"("存入栈，只要用一个int记录栈中元素数量即可，反正它们都是"("嘛。
