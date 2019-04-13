644 Maximum Average Subarray II 
===========================================
给定一个有n个整数的数组，找出一个连续的子数组，要求其长度至少为k，且拥有最大的平均值。请输出这个最大平均值。

Example 1:

Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation:
when length is 5, maximum average value is 10.8,
when length is 6, maximum average value is 9.16667.
Thus return 12.75.

Note:
    1 <= k <= n <= 10,000.
    Elements of the given array will be in range [-10,000, 10,000].
    The answer with the calculation error less than 10-5 will be accepted.


二分查找
----------------------------
设min、max分别为数组nums中的最大值和最小值，那么数组里任何几个数的平均数一定在[min, max]之间，因为平均数不可能比min小，也不可能比max大。

算法思路如下：既然问题让我们求平均数，那么它一定在[min, max]之间。不妨猜测最大平均数为mid = (min + max) / 2，然后我们去验证一下是否存在一个子数组，其平均数大于等于mid？如果存在，说明我们还可以继续往高里猜，令min = mid，开始新一轮探测；如果不存在，说明我们猜得太高了，需要往低里猜，令max = mid, 开始新一轮探测。当mid的值在一个很小的范围内浮动时，我们可以认为已经找到了要求的平均数。

那么如何判断mid是高还是低呢？看以下分析。假设存在长度为j的子数组a1, a2, a3, ..., aj，且其平均值比mid大，可以知道：

- (a1 + a2 + a3 + ... + aj) / j > mid
- (a1 + a2 + a3 + ... + aj) > mid * j
- (a1 - mid) + (a2 - mid) + (a3 - mid) + ... + (aj - mid) > 0

因此，只要遍历长度至少为k的子数组，将每个元素都减去mid后求和。如果最后的和sum大于0，那就说明存在这样一个子数组，其平均数大于mid，我们下次可以猜一个更大的数；反之，则不存在这样一个数组，下次我们需要猜小一点。

那么，怎么快速判断是否存在这样一个数组呢？可以用常用的“累积和”的手法：设sum[i]为nums[0] + nums[1] + ... + nums[i]，那么任意一个子数组的和都可以快速求出： sum[j] - sum[i] = nums[i+1] + ... + nums[j-1] + nums[j]。本问题中，我们设sum[i] = nums[0] - mid + nums[1] - mid + ... + nums[i] - mid。问题转化为找出一个大于0的sum[j] - sum[i]，且j - i >= k。看以下代码::

    50         vector<int>::size_type length = nums.size();
    51         for (int i = k; i < length; ++i) {
    52             sum += nums[i] - mid;
    53             prev += nums[i - k] - mid;
    54             min_sum = (prev < min_sum) ? prev : min_sum;
    55             if (sum >= min_sum)
    56                 return true;
    57         }

观察代码可以发现变量sum就是sum[j]，prev则是代表sum[i]，j - i >= k。
