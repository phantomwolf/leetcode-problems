31.Next Permutation 
===========================================
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column::

    1,2,3 → 1,3,2
    3,2,1 → 1,2,3
    1,1,5 → 1,5,1

分析
----------------------------------
特殊情况
+++++++++++++++++++++++++++
输入数据已经降序排序的情况下，将数组反转即可。时间复杂度O(n)。

产生比原来大的置换
+++++++++++++++++++++++++++
输入数据的每个位置(用逗号隔开)，最左边的是最显著位(最高位)。比较两个输入时，从左边的最显著位开始，依次比较每个位置上的数。因此，设high < low，且nums[high] < nums[low]，将nums[high]与nums[low]交换后，nums[high]比原来大，high左边的位没有变化，因此产生的结果要比原来大。之后，不论high右边的位如何变化，最终结果都比原来要大。

产生刚好比原来大的置换
+++++++++++++++++++++++++++
要产生刚好比原来大的置换，首先，high要尽可能靠近右边；其次，要用high右边的、刚好大于nums[high]的nums[low]来做交换(这样nums[high]增大的幅度最小)；最后，high右边的位必须调整为最小，即增序排序。

既需要保证high的右边存在nums[low]，满足nums[high] < nums[low]，又要high尽可能得小。我们可以从右向左扫描，直到遇到一个比它右边的元素小的元素，这就是nums[high]。(隐含条件：high右边的元素呈降序排序)

要找刚好比nums[high]大的元素，只要从high + 1开始向右寻找即可，反正右边元素是降序排序。

找到low以后，将nums[high]和nums[low]交换。由于nums[low - 1] >= nums[low] > nums[high] >= nums[low + 1]，所以将两者交换后，high右边的元素仍为降序排序。

nums[high]确定后，已可以保证结果大于原来的数。如何让结果尽可能小？将high右边的元素变为增序排序即可。由于high右边已为降序排序，因此用O(n)时间反转它们即可，而不需要用O(nlogn)时间来排序。
