# 879. Profitable Schemes
There are G people in a gang, and a list of various crimes they could commit.

The i-th crime generates a profit[i] and requires group[i] gang members to participate.

If a gang member participates in one crime, that member can't participate in another crime.

Let's call a profitable scheme any subset of these crimes that generates at least P profit, and the total number of gang members participating in that subset of crimes is at most G.

How many schemes can be chosen?  Since the answer may be very large, return it modulo 10^9 + 7.

 

## Example 1:

Input: G = 5, P = 3, group = [2,2], profit = [2,3]
Output: 2
Explanation: 
To make a profit of at least 3, the gang could either commit crimes 0 and 1, or just crime 1.
In total, there are 2 schemes.

## Example 2:

Input: G = 10, P = 5, group = [2,3,5], profit = [6,7,8]
Output: 7
Explanation: 
To make a profit of at least 5, the gang could commit any crimes, as long as they commit one.
There are 7 possible schemes: (0), (1), (2), (0,1), (0,2), (1,2), and (0,1,2).

 

## Note:

    1 <= G <= 100
    0 <= P <= 100
    1 <= group[i] <= 100
    0 <= profit[i] <= 100
    1 <= group.length = profit.length <= 100

## Solution
Approach 1: Dynamic Programming

Intuition

We don't care about the profit of the scheme if it is ≥P, because it surely will be over the threshold of profitability required. Similarly, we don't care about the number of people required in the scheme if it is >G, since we know the scheme will be too big for the gang to execute.

As a result, the bounds are small enough to use dynamic programming. Let's keep track of cur[p][g], the number of schemes with profitability p and requiring g gang members: except we'll say (without changing the answer) that all schemes that profit at least P dollars will instead profit exactly P dollars.

Algorithm

Keeping track of cur[p][g] as defined above, let's understand how it changes as we consider 1 extra crime that will profit p0 and require g0 gang members. We will put the updated counts into cur2.

For each possible scheme with profit p1 and group size g1, that scheme plus the extra crime (p0, g0) being considered, has a profit of p2 = min(p1 + p0, P), and uses a group size of g2 = g1 + g0.

要点：

* cur[p][g]表示利润为p，需要g人的方案的数量
* 若一个方案的利润大于p，同样记为p，我们并不关心利润是大于还是等于P
* 之所以需要cur和cur2两个辅助数组，是因为不这样的话，会导致有些数据被重复计算
