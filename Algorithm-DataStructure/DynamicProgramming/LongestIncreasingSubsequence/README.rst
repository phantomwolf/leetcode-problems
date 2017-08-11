Longest Increasing Subsequence
=============================================
最长递增子序列(Longest Increasing Subsequence)问题，是在序列中寻找一个最长的子序列，使得其元素从小到大递增。子序列不需要连续，可以包含重复元素。

O(nlogn) algorithm
-----------------------
除动态规划外，还有一个更加有效的算法。维护一个叫做active_lists列表，存放active list，即有可能成为LIS的序列。初始状态时，该表为空。顺序扫描输入序列A，有3种可能的情况::

1. 如果A[i]比所有active list的末尾元素都小，创建一个以A[i]开头的新active list，加入到active_lists中。原因：active_lists中保存了目前为止所有可能成为LIS的序列(注意第2种情况中，序列是经过复制的)。如果A[i]并不能扩展其中任何一个，那就只能以它为开头，创建一个新的list。
2. 如果A[i]比所有active list的末尾元素都大，将最长的active list复制一份，并在新list后加上A[i]。注意是复制，原来的较短的list依然有可能成为最终的LIS(比如后续的元素都比A[i]要小，原来的较短的list反而有可能添加后续元素，扩展得更长)。
3. 如果A[i]位于所有末尾元素的中间，找到小于A[i]的末尾元素中最大的那个，并用A[i]来扩展它。所有与这个新生成的active list长度相等的list都将被抛弃。原因：这些被抛弃的list，其长度与新生成的list相等，且末尾元素大于新list，它们最终不可能比新list更长。
