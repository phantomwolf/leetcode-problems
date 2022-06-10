# 870. Advantage Shuffle

You are given two integer arrays nums1 and nums2 both of the same length. The advantage of nums1 with respect to nums2 is the number of indices i for which nums1[i] > nums2[i].

Return any permutation of nums1 that maximizes its advantage with respect to nums2.

## Example 1

```
Input: nums1 = [2,7,11,15], nums2 = [1,10,4,11]
Output: [2,11,7,15]
```

## Example 2

```
Input: nums1 = [12,17,8,32], nums2 = [18,25,32,11]
Output: [32,8,17,12]
```

## Constraints:

* 1 <= nums1.length <= 105
* nums2.length == nums1.length
* 0 <= nums1[i], nums2[i] <= 109

# Solution

思路：将nums1中找出能打败nums2中元素的数字，将两者存入Map；如果nums1中某元素不能打败任何nums2中的元素，就将其视为弃子，随意配对。

以第2个例子为例。准备一个Map来存放nums1和nums2的mapping，和一个Queue(List也行)来存放无法满足条件的弃子。

将nums1和nums2排序，用i和j分别表示两者的下标，比较nums1[i]和nums2[j]:

```
i = 0, j = 0
nums1: [ 8, 12, 17, 32]
nums2: [11, 18, 25, 32]
```

可知nums1[0] < nums2[0]。因为nums2现在是有序的，因此nums1[0]不可能大于nums2中的任何元素，nums1[0]只是一枚弃子。我们将nums1[0]存入一个Queue，并让i前进:

```
i = 1, j = 0
nums1: [ 8, 12, 17, 32]
nums2: [11, 18, 25, 32]
```

可知nums1[1] > nums2[0]，将两者配对，存入Map中，可以理解为nums1[1]可以用来打败nums2[0]。将i和j同时前进一位：

```
i = 2, j = 1
nums1: [ 8, 12, 17, 32]
nums2: [11, 18, 25, 32]
```

可知nums1[2] < nums2[1]，由于nums1和nums2都有序，可知nums1[2]已经不可能大于nums2中的任何剩余元素了（nums2[0]已经在上一次用掉了），因此nums1[2]是弃子，放入队列。

将i前进一位，得到nums1[3] > nums2[1]，存入Map。最终我们得到12 > 11与32 > 18两对组合，可以满足nums[i] > nums[j]，nums1中的其余元素都是弃子，不能满足条件。对nums2中的每个元素，我们都从Map中寻找对应的能打败它的元素。如果找不到，就从Queue中取出一枚弃子，与该元素配对。
