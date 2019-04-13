229. Majority Element II 
=============================================
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.


空间复杂度O(n)算法
-----------------------------------
用一个哈希表，统计每个元素出现的次数。最后找出次数超过1/3的元素即可。

Moore's Voting算法
-----------------------------------
原本的Moore's Voting算法只能选中出现1/2的元素，因此我们需要将起修改一下。

假设数组中有2个数量超过1/3的元素，出现次数超过1/3的元素至多2个。我们只要设置2个candidate，使它们两个之间互相不竞争，只与剩余元素竞争。由于这俩元素的数量均多于所有剩余元素的数量和，因此能够在竞争中存活下来。
