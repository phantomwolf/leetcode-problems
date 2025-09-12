# 295. Find Median from Data Stream
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

* For example, for arr = [2,3,4], the median is 3.
* For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.

Implement the MedianFinder class:

* MedianFinder() initializes the MedianFinder object.
* void addNum(int num) adds the integer num from the data stream to the data structure.
* double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

Example 1:

Input:

    ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
    [[], [1], [2], [], [3], []]
    Output
    [null, null, null, 1.5, null, 2.0]

Explanation:

    MedianFinder medianFinder = new MedianFinder();
    medianFinder.addNum(1);    // arr = [1]
    medianFinder.addNum(2);    // arr = [1, 2]
    medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
    medianFinder.addNum(3);    // arr[1, 2, 3]
    medianFinder.findMedian(); // return 2.0

Constraints:

* -105 <= num <= 105
* There will be at least one element in the data structure before calling findMedian.
* At most 5 * 104 calls will be made to addNum and findMedian.

Follow up:

* If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
* If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?

## Solution 1: insertion sort
We can do insertion sort to the input. Each time `addNum` is called, insert the new num to the correct location, so that the entire input is sorted.

* `findMedian` will be fast: time complexity O(1).
* `addNum` will be slow: time complexity O(n). Suppose there're n elements, so the total time complexity for adding all of them is O(n^2).

## Solution 2: two heaps(recommended)
Imagine spliting the input into 2 parts: all elements in left part are no greater than those in the right parts. If we can quickly find the greatest num in the left part and the smallest num in the right part, we can calculate the median immediately.

To achieve this, we use 2 heaps to store the inputs: `leftHeap` is a max heap and represents the left part; `rightHeap` is a min heap and represents the right part. We also limit the sizes of the two heaps: `leftHeap.size() == rightHeap.size()` or `leftHeap.size() == rightHeap.size()+1`. When the heap sizes don't fulfill the limitation, `balance()` operation is done to move some nums from one heap to another.

When there're even number of elements, `leftHeap` and `rightHeap` have same sizes, and median will be `(leftHeap.top()+rightHeap.top()) / 2`. When there're odd number of elements, median will be `leftHeap.top()`.

**Supporting deletion**

To support deletion, we'll have to delete elements from heaps. However, there's no easy way to do so(we'll have to iterate the entire heaps).

An efficient way is "lazy deletion": when deleting a num, we use a map to record the amount of that num we need to delete. Meanwhile, we use two variables `leftSize` and `rightSize` to record the logical sizes of two heaps. When deleting num, or doing `balance()`, we always check the heap top to see if we can do a real deletion.
