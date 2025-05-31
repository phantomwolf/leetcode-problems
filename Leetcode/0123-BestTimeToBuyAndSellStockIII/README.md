# 123. Best Time to Buy and Sell Stock III
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.

Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

Constraints:

* 1 <= prices.length <= 105
* 0 <= prices[i] <= 105

## 分析
特点：最多可以进行2次事务（一次买入+一次卖出叫一个事务）；买入之后，必须先卖出，才能再次买入。

表面上看没有太大变化，实际上却让问题复杂化了。

.. image:: prices.jpg

首先，买入与卖出并不一定是相邻的谷与峰。我们可以在某个价格低谷处买入，然后不急着卖出，等到某一个价格很高的高峰再卖出。

其次，第一个事务会影响第二个的结果。假设我们第一次买入后，很久都没有卖出，导致错过了很多价格低谷，耽误了第二次买入，那么第二个事务的利润也会受到影响。

## Solution 1: Generic Dynamic Programming
[# 188. Best Time to Buy and Sell Stock IV](../0188-BestTimeToBuyAndSellStockIV/README.md)

## Solution 2: Bidirectional Dynamic Programming
If we divide prices[] into 2 parts, each part will be an independent "121. Best Time to Buy and Sell Stock" problem, and each sub-problem can be solved with O(n) time complexity. However, there're n ways to partition prices[], so the overall time complexity will be O(n^2).

We can introduce 2 arrays:

* `leftProfits[i]` is the maximum profit we can get using prices[0, i]
* `rightProfits[i]` is the maximum profit we can get using prices[i, n-1]

If we divide the prices[] into `prices[0, i]` and `prices[i+1, n-1]`, the max profit will be `leftProfits[i] + rightProfits[i+1]`.

This can be space-optimized. Instead of using leftProfits[] array, we can use a single variable leftProfit to track the maximum profit while scanning from left to right, just like what we did in "121. Best Time to Buy and Sell Stock" problem.

Time complexity: O(n). Space complexity: O(n).

## Solution 3: Four Variables
We can consider the problem as a game, and we as agent could make at most two transactions in order to gain the maximum points (profits) from the game. The two transactions be decomposed into 4 actions: "buy of transaction #1", "sell of transaction #1", "buy of transaction #2" and "sell of transaction #2". We use 4 variables to denote the account's balance after each action:

* buy1: account balance after "buy of transaction #1". Initial value: int min.
* sell1: account balance after "sell of transaction #1". Initial value: 0.
* buy2: account balance after "buy of transaction #2". Initial value: int min.
* sell2: account balance after "sell of transaction #2". Initial value: 0.

Their relationships:

    buy1 = max(buy1, -prices[i])
    sell1 = max(sell1, buy1+prices[i])
    buy2 = max(buy2, sell1-prices[i])
    sell2 = max(sell2, buy2+prices[i])

### 注意事项1

.. image:: prices.jpg

看价格曲线图可知，获取最高利润的方法是，在第1天买入，第2天卖出，在第3天买入，第4天再卖出。然而，第3天的买入价格低于第1天，当i = 3时，buy1会被更新为0，表示在第3天进行第一次买入。这样会不会引起问题呢？

答案是不会的。虽然buy1被更新为第3天买入，但并不代表sell1、buy2、sell2也会跟着更新，因为仅当结果更大时，这些变量才会更新。就算buy1更新了，用于计算sell1的buy1，说不定是之前的另一个值。

### 注意事项2
若buy1在i处更新，说明在该处进行第一次买入，可以使资产最多；若sell1在i处更新，说明在该处进行第一次卖出，可以使资产最多。buy2、sell2同理。这也隐含了一个限制：一次循环只能有一个变量更新，因为一天只能进行一个动作，如果buy1和sell1同时在i处更新，那就表示在第i天同时进行了买入和卖出操作，这是不允许的。

算法会有这个问题么？答案是不会的。假设buy1在i处更新，那么::

    buy1 = -prices[i]

此时sell1的新值为::

    buy1 + prices[i] = -prices[i] + prices[i] = 0

sell1的初始值就是0，且只在遇到更大的值后才会更新，因此sell1不可能比0小，绝对不会更新。同理，buy2、sell2也不会更新。
