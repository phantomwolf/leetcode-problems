121 Best Time to Buy and Sell Stock 
================================================
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:

Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)

Example 2:

Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.


思路
-------------------------------
设我们在第i天买入，第j天卖出，i < j。由于只能买入一次，卖出一次，所以我们得找出差价最大的两天，使得::

    profit = price[j] - price[i], i < j

的值最大。

假设我们在第j天卖出，所以买入时可能的价格范围是price[0..j-1]。何时买入最好呢？当然是最便宜的时候，因此我们可以用一个变量min_price，来记录price[0..j-1]的最小值。因此，在第j天卖出的最大利润是profit = price[j] - min_price。如果min_price大于price[j]，说明在这一天卖出是赚不到任何钱的。

除了第一天以外，我们计算在每一天卖出的最大利润，然后求出总的最大利润。
