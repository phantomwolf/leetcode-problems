76 Minimum Window Substring 
============================================
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example::

    S = "ADOBECODEBANC"
    T = "ABC"

Minimum window is "BANC".

Note:

- If there is no such window in S that covers all characters in T, return the empty string "".
- If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S. 


题目解释
--------------------------------
题目说“包含T中的所有字符”，同样要求字符的数量。如果T中有m个a，那么返回结果中必须有同样数量的a。


解答
--------------------------------
有点类似Subset那一类题。首先，若S的长度小于T，那么S的子字符串不可能包含T中所有字符，直接返回空字符串。

设置两个下标i = j = 0，令j向右前进，直到S[i..j]包含T中的所有字符。然后，在S[i..j]包含T中所有字符的前提下，令i向右前进，直到不能再前进为止。此时，我们找到了一个满足条件的候选，记录其S[i..j]的长度。

接着，我们令i前进一位，此时S[i..j]必然不包含T中所有字符。重复上述过程。跟踪所有满足条件的S[i..j]的长度的最小值，以及相应的i和j。

怎样在常数时间内，判断S[i..j]是否包含T中所有字符呢？我们需要设置::

    int S_count[128] = {0};
    int T_count[128] = {0};
    int count;
    
执行算法之前，扫描一遍T，用T中字符做下标，记录每个字符出现的次数::

    T_count[i]++;

算法执行过程中，我们同样记录S中每个字符出现的次数。当我们扫描到字符S[j]时，如果S_count[S[j]]尚未超过T_count[S[j]]，这说明S[i..j]中，字符S[j]的数量尚未达到T中字符S[j]的数量。此时，我们令count自增，表示T中又有一个字符在S[i..j]中出现了。当count == T.size()时，表示T中所有字符都在S中出现了。因此我们可以在O(n)时间内判断S[i..j]是否包含T中所有字符。
