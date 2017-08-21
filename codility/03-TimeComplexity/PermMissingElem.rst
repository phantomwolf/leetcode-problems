Permutation Missing Element
=======================================
Find the missing element in a given permutation. 

描述
------------------------------
A zero-indexed array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.

Your goal is to find that missing element.

Write a function::

    int solution(vector<int> &A);

that, given a zero-indexed array A, returns the value of the missing element.

For example, given array A such that::

    A[0] = 2
    A[1] = 3
    A[2] = 1
    A[3] = 5

the function should return 4, as it is the missing element.

Assume that::

        N is an integer within the range [0..100,000];
        the elements of A are all distinct;
        each element of array A is an integer within the range [1..(N + 1)].

Complexity:

- expected worst-case time complexity is O(N);
- expected worst-case space complexity is O(1), beyond input storage (not counting the storage required for input arguments).

Elements of input arrays can be modified.

解法1：XOR
------------------------------
之前我们遇到过一个类似的问题：OddOccurrencesInArray。本题的区别是，每个元素只出现一次；有一个位于[1, N+1]中的元素并未出现。

本题也可以用异或法来解。观察可知，数组A下标的范围是[0, N)，共N个数字；数组A中元素的范围是[1, N+1]，也是N个数字。我们可以将数组的下标，类比成OddOccurrencesInArray中元素的第二次出现，用来做XOR。
