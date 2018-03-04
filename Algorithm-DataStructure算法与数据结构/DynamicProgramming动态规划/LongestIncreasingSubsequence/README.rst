Longest Increasing Subsequence
=============================================
最长递增子序列(Longest Increasing Subsequence)问题，是在序列中寻找一个最长的子序列，使得其元素从小到大递增。子序列不需要连续，可以包含重复元素。

O(nlogn) algorithm
-----------------------
除动态规划外，还有一个更加有效的算法。维护一个叫做active_lists列表，存放active list，即有可能成为LIS的序列。初始状态时，该表为空。顺序扫描输入序列A，有3种可能的情况::

1. 如果A[i]比所有active list的末尾元素都小，创建一个以A[i]开头的新active list，加入到active_lists中。原因：active_lists中保存了目前为止所有可能成为LIS的序列(注意第2种情况中，序列是经过复制的)。如果A[i]并不能扩展其中任何一个，那就只能以它为开头，创建一个新的list。
2. 如果A[i]比所有active list的末尾元素都大，将最长的active list复制一份，并在新list后加上A[i]。注意是复制，原来的较短的list依然有可能成为最终的LIS(比如后续的元素都比A[i]要小，原来的较短的list反而有可能添加后续元素，扩展得更长)。
3. 如果A[i]位于所有末尾元素的中间，找到小于A[i]的末尾元素中最大的那个，并用A[i]来扩展它。所有与这个新生成的active list长度相等的list都将被抛弃。原因：这些被抛弃的list，其长度与新生成的list相等，且末尾元素大于新list，它们最终不可能比新list更长。

实现
~~~~~~~~~~~~~~~
上述算法很容易写成空间复杂度为O(n^2)，用一个list<list<int>> active_lists来保存每一个active list。但是仔细观察后会发现：

- active_lists里，不会出现两个长度相同的list，由于规则3，相同长度的list都被抛弃了
- 我们只需要将每个active list的末尾元素与A[i]相比较即可，并不需要其它元素

由于以上性质，我们用一维数组tail[n]来保存每个active list的末尾元素，tail[i]就保存长度为i+1的active list的末尾元素。这就足够了。

具体实现见leetcode/300-LongestIncreasingSubsequence
