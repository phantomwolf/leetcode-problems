Order statistic(顺序统计)
====================================
在统计学中，样本的第k顺序统计量，就是第k小的值。这一问题被成为Selection Problem，相应的算法成为Selection Algorithm。这类问题包含以下子问题：寻找最小值、最大值、中间值。

我们以第k小的元素为例

第k小的元素
====================================
1 排序或部分排序
-------------------------------
将整个数组从小到大排序，然后找第k个位置的数，就是第k小的元素。或者用Selection Sort(即每次从剩余元素中找出最小值，然后放到正确的位置)算法，排序到第k个数字时，就找到了第k小的元素。

时间复杂度：取决于排序算法的选择。如果选择快速排序之类的算法，那么时间复杂度为平均情况下O(nlogn)，最坏情况下为O(n^2)；如果用Selection Sort，只需排序前k个数就能解决问题，故为O(k)。

2 最小堆
-------------------------------
用O(n)的时间复杂度，将整个数组构建成最小堆，然后执行k次extract_min()，第k次得到的数就是第k小的数。

时间复杂度：最小堆的extract_min()操作时间复杂度为O(logn)，需要执行k次，再加上建堆的开销，故为O(n + klogn)

3 最大堆
-------------------------------
最大堆的性质是，最大的元素在堆的顶端。我们只要把元素中最小的k个元素，统统放入最大堆里，堆顶就是我们要的第k小的元素。过程如下：

1. 将数组的前k个元素( [arr[0], arr[k-1]] )构建成最大堆
2. 遍历数组中剩下的n - k个元素。如果该元素比最大堆的堆顶元素要小(说明该元素比堆里的k个元素都要小)，那就将堆顶元素替换成该元素，并执行max_heapify()，恢复堆的性质；否则就忽略，看下一个元素。
3. 遍历完成时，堆中的k个元素必定是数组中前k小的那些数。由于最大堆的性质，最大的数在堆顶，因此堆顶元素就是我们要找到的第k小的元素。

时间复杂度：将k个元素构建成最大堆，需要O(k)；堆每插入一个元素都是O(logn)，其中n为堆中总元素的数量，所以第二步为O((n-k) * logk)。总共为：O(k + (n-k)*logk)

4 QuickSelect
-------------------------------
这个算法是快速排序(QuickSort)的作者发明的，采用与快排相似的分区方法。在快速排序中，我们每次选出一个pivot，将小于它的元素放在左边，大于它的放右边，最后将pivot放入正确的位置。在QuickSelect算法中，当发现pivot就是第k小的数时，我们就可以停止了。

注意采用Hoare’s Partition Scheme(即从数组的两头分别找需要交换的数)，这样对于全部都是重复元素的情况下，分区也很快。

时间复杂度：与快排相似，pivot的选择十分重要，当完全随机选取pivot时，期望时间复杂度为O(n) (不同于快排，每次只需要处理两个分区其中的一边)。此算法最坏情况时(比如数组中所有元素都相等)，时间复杂度为O(n^2)。

5 IntroSelect
-------------------------------
与QuickSelect类似，但采用median of medians策略，来寻找一个好的pivot。可以保证在最坏情况下仍然能达到O(n)的时间复杂度。

median of medians策略
++++++++++++++++++++++++++
将数组分为5个一组，分别求这些小组的中位数(median)，一般使用插入排序就可以。然后再将这些中位数分为5个一组，再求这些小组的中位数(median)。重复上述操作，直到最后只剩下一个数。

如果不限制修改原本的数组，median of medians策略是可以原地执行的(in-place，即不需要额外的空间)：每次求出一个小组的中位数(median)后，都将其swap到数组的最前面，然后再将最前面这些数分为5个一组，继续求中位数。

递归版本
++++++++++++++++++++++++++
我们需要以下函数：

- intro_select(): 最主要的函数，调用pivot()从[left, right]中选一个值做pivot，再执行partition()函数，进行分区，并更新left或right。重复上述过程，直到pivot就是第k小的数
- pivot(): 采用median of medians策略，将数组分为5个一组，对每个小组求中位数(利用插入排序)，并将这些中位数swap到数组最前面，然后调用intro_select()来求这些中位数的中位数。(看起来好像pivot()调用了intro_select()，但由于intro_select()是它的最后一条语句，所以是尾递归。所以其实相当于intro_select()自己调用了自己)。如果要求中位数的范围小于等于5，就直接调用median5()求出其中位数。
- median5(): 求5个或以下元素的中位数，采用插入排序法。
- partition(): 将数组分为2部分，左边都小于pivot，右边都大于pivot。与quick_select相比，多了一个参数pivot，即pivot由外部指定。

算法如下：

1. 用median of medians策略，将数组分为5个一组，分别求小组的中位数，并swap到数组的最前面。
2. 将上述ceil(n/5)组各自排序，并找出各自的中位数。创建一个辅助数组median[ceil(n/5)]，保存这些中位数。
3. 求出这些中位数们的中位数：median_of_median
4. 将数组按照median_of_median来分区：pos = partition(array, n, median_of_median);
5. 如果pos == k，那就返回median_of_median，我们找到了第k小的元素；如果pos < k，那就对数组左边递归调用上述过程；如果pos > k，那就对数组右边递归进行上述过程。

Leetcode Problems
==========================
- 1985. Find the Kth Largest Integer in the Array: https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/
- 215. Kth Largest Element in an Array: https://leetcode.com/problems/kth-largest-element-in-an-array/
