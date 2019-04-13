# 1021. Remove Outermost Parentheses
A valid parentheses string is either empty (""), "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.  For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.

A valid parentheses string S is primitive if it is nonempty, and there does not exist a way to split it into S = A+B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string S, consider its primitive decomposition: S = P_1 + P_2 + ... + P_k, where P_i are primitive valid parentheses strings.

Return S after removing the outermost parentheses of every primitive string in the primitive decomposition of S.

## Example 1
Input: "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".

## Example 2
Input: "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".

## Example 3
Input: "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".

## Note
* S.length <= 10000
* S[i] is "(" or ")"
* S is a valid parentheses string

## 基本思路
此题与“括号匹配”问题类似，准备一个栈stack。由Note中的性质可知，S中有一半"("，一半")"，各5000个。因此，栈的最大大小为5000。扫描字符串S，遇到"("则入栈，遇到")"则出栈。

何为primitive的字符串？对应到上述扫描的过程，从stack.size()为0开始，直到stack.size()从非0再度变为0，这期间扫描过的子字符串，即为一个primitive的字符串。

知道了如何识别primitive字符串，那么如何去掉这种字符串最外层的括号呢？在扫描的过程中动些手脚就可以了：

* 当stack.size()由0变为1时，这说明我们扫描到了primitive字符串的最外层的左括号，这时不往结果中写入"("
* 当stack.size()由1变为0时，这说明我们扫描到了primitive字符串的最外层的右括号，这时不往结果中写入")"
* 其余的时候，遇到"("则向结果中写入"("，遇到")"则向结果中写入")"

最终，我们得到的字符串就是正确结果。
