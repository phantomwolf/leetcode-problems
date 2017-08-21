================================================
OddOccurrencesInArray
================================================
-------------------------------------
Find value that occurs in odd number of elements.
-------------------------------------

描述
==================================
A non-empty zero-indexed array A consisting of N integers is given. The array contains an odd number of elements, and each element of the array can be paired with another element that has the same value, except for one element that is left unpaired.

For example, in array A such that:
  A[0] = 9  A[1] = 3  A[2] = 9
  A[3] = 3  A[4] = 9  A[5] = 7
  A[6] = 9

        the elements at indexes 0 and 2 have value 9,
        the elements at indexes 1 and 3 have value 3,
        the elements at indexes 4 and 6 have value 9,
        the element at index 5 has value 7 and is unpaired.

Write a function:

    int solution(vector<int> &A);

that, given an array A consisting of N integers fulfilling the above conditions, returns the value of the unpaired element.

For example, given array A such that:
  A[0] = 9  A[1] = 3  A[2] = 9
  A[3] = 3  A[4] = 9  A[5] = 7
  A[6] = 9

the function should return 7, as explained in the example above.

Assume that:

        N is an odd integer within the range [1..1,000,000];
        each element of array A is an integer within the range [1..1,000,000,000];
        all but one of the values in A occur an even number of times.

Complexity:

        expected worst-case time complexity is O(N);
        expected worst-case space complexity is O(1), beyond input storage (not counting the storage required for input arguments).

Elements of input arrays can be modified.


解法1：XOR
------------------------
将数组中所有元素进行异或XOR操作，出现偶数次的数会被“中和”掉，最后留下的就是那个只出现一次的数。

时间复杂度：O(N)；空间复杂度：O(1)


问题变种
------------------------
此问题有一个变种，增加了一个限制条件：数组有序。在这种情况下，有一个O(logN)的算法：二分查找。

数组有序，那么相同的2个数必定相邻。考虑以下数组::

    A: [1, 1, 2, 2, 3, 4, 4, 5, 5, 6, 6]，长度为11
    B: [1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6]，长度为11

对其进行二分查找，p = (0 + 10) / 2 = 5。A[5] = 4，和周围元素对比，会发现它是第1个4；B[5] = 3，和周围元素对比发现其为第2个3。为什么会有如此差异呢？因为只出现一次的元素的位置不同。可以发现，当p指向第1个元素时，目标元素出现在左边；当p指向第二个元素时，目标元素出现在右边。根据此规律，我们可以进行二分查找，直到找到仅出现一次的元素。

时间复杂度：O(logN)；空间复杂度：O(1)
