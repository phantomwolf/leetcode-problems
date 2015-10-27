457. Circular Array Loop 
=====================================
问题描述
----------------
You are given an array of positive and negative integers. If a number n at an index is positive, then move forward n steps. Conversely, if it's negative (-n), move backward n steps. Assume the first element of the array is forward next to the last element, and the last element is backward next to the first element. Determine if there is a loop in this array. A loop starts and ends at a particular index with more than 1 element along the loop. The loop must be "forward" or "backward'.

Example 1: Given the array [2, -1, 1, 2, 2], there is a loop, from index 0 -> 2 -> 3 -> 0.

Example 2: Given the array [-1, 2], there is no loop.

Note: The given array is guaranteed to contain no element "0".

Can you do it in O(n) time complexity and O(1) space complexity? 

分析
----------------
经过分析可知，数组中每个元素都指向一个固定的位置，这其实就是一个由数组模拟的链表，它与普通的数组链表有以下不同：

- 元素的值并不表示指向的位置，而是表示前进/后退的步数（取决于它是正还是负）。因此元素指向的位置为：(i + nums[i]) mod nums_size。需要注意的是，在C中-1 % 2 == -1，如果得到了负数，我们需要将其加上nums_size。
- 链表的结尾是这样表示的：如果一个元素指向的位置就是它本身，即元素的值nums[i] % nums_size == 0，就表示链表结尾。

我们可以用弗洛伊德判圈算法来探测环。
