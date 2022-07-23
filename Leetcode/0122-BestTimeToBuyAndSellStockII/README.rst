122 Best Time to Buy and Sell Stock II
==================================================
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).


思路
---------------------
与上一个题不同，本题可以无限次进行买入卖出操作，但买入后必须先卖出才能再次买入。

将股票的价格画成图表，是一个折线图。我们只需在谷处买入，在峰处卖出，就可以获得最大利润。峰谷处都是拐点，即价格趋势开始变化的地方。
