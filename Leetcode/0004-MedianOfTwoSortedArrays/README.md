# Problem
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

# 问题
有两个已排序的数组nums1和nums2，它们的长度分别为m和n。找出这两个数组的中位数（即把两个数组合并并排序后，位于正中间的数。如果合并后数组长度为偶数，则求正中间两个数的平均值），要求不能把两个数组合并。
分析
可以转化为一个更宽泛的问题：有两个已排序的数组nums1和nums2，求合并后的第k小的数（如果合并后长度为偶数，则求第k和k+1小的数的平均值）。在本问题中，k值为(m+n)/2。为了简化，以下解法只查找第k小的数。

## 解法1
类似归并排序的合并过程。不断比较nums1和nums2开头的数，并将较小的一个抛弃，直到第k个数。复杂度O(m+n)

## 解法2: 二分查找
二分查找，时间复杂度O(logn)。先来看一个典型输入：

```
nums1 = [1, 5, 9]
nums2 = [3, 7]
```

如果将两个数组合并，可以得到`[1, 3, 5, 7, 9]`，其中位数（median）为5。那么如何不合并数组就求出结果呢？

我们将合并后的数组分成两部分，其中中位数在左半部分，即`[1, 3, 5 | 7, 9]`。可知nums1中有1个元素被分到了左边，nums2有2个，即

```
       left1    right1
nums1 = [1,   |   5,    9]
nums2 = [3    |   7]
       left2    right2
```

设左半部分最后一个元素为left1/left2，右半部分第一个元素为right1/right2。可知，left1 < right2且left2 < right1。这时，right1和right2中较小的就是中位数，这是因为nums1和nums2的左半部分加起来大小是合并后数组的一半，且nums1和nums2左半部分里的任何元素，都比右半部分的要小。根据中位数的定义，我们已经找到了中位数。

这个划分方法对偶数个元素的输入同样适用，例如对于以下输入：
1 3 5 7 8 9
```
              left1   right1
nums1 = [1,     5   |   9]
nums2 = [3   |  7,      8]
      left2   right2
```

因为是元素总数为偶数个，左右两半部分大小相等，因此用于计算中位数的两个元素分别是左边最大的元素和右边最小的元素，即`(max(left1, left2) + min(right1, right2)) / 2`。

### 越界
根据nums1和nums2的大小和内容，有可能会出现越界的情况。比如：

```
nums1 = [1  | ]
nums2 = [2, | 3, 4, 5]
```

最终的结果为3。按二分查找的算法进行查找时，right1会越界。这时只要规定向右越界的值为无限大即可。

再看以下输入：

```
nums1 = [      | 5]
nums2 = [1, 2, | 3, 4]
```

二分搜索的第一轮：

```
lo1 = 0, hi1 = 0, mi1 = 0, mi2 = 5 / 2 - 0 - 2 = 0
left1 = 5, right1 = INT_MAX, left2 = 1, right2 = 2
```

因为left1 > right2，因此mi1需要向左移。令hi1 = mi1 - 1 = -1，第二轮循环：

```
lo1 = 0, hi1 = -1, mi1 = floor((lo1 + hi1) / 2.0) = -1, mi2 = 5/2 - (-1) - 2 = 1
left1 = INT_MIN, right1 = 5, left2 = 2, right2 = 3
```

由于left1 < right2且left2 < right1，因此我们成功找到了正确的划分。由于总共有奇数个元素，因此最终结果为min(right1, right2) = 3。

注意事项：mi1的值并非`(lo1 + hi1) / 2`，而是`floor((lo1 + hi1) / 2.0)`。这是因为当lo1 + hi1为-1时，前者的值为0，后者为-1。我们想要的是后者，否则当lo1=0, hi1=-1时，mi1将无法移动到数组外面。
