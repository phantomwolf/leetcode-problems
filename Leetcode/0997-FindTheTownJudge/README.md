# 997. Find the Town Judge
In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

    The town judge trusts nobody.
    Everybody (except for the town judge) trusts the town judge.
    There is exactly one person that satisfies properties 1 and 2.

You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

## Example 1:

Input: n = 2, trust = [[1,2]]
Output: 2

## Example 2:

Input: n = 3, trust = [[1,3],[2,3]]
Output: 3

## Example 3:

Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1

## Constraints:

* 1 <= n <= 1000
* 0 <= trust.length <= 104
* trust[i].length == 2
* All the pairs of trust are unique.
* ai != bi
* 1 <= ai, bi <= n

## Solution 1: two arrays
The trust relationships form a graph. Each trust pair, [A, B] represents a directed edge going from A to B. Based on the definition of town judge, the graph node of town judge should have in degree of n-1 and out degree of 0.

## Solution 2: one array
In solution 1, we use 2 arrays to record in degree and out degree. However, we can use one array to record the value of "indegree - outdegree". Based on the definition, the town judge should have in degree of n-1 and out degree of 0, thus its "indegree - outdegree" should be n-1.

Besides the town judge, everyone else's in degree will be less than n-1 and out degree will be greater than or equal to 0. This means the "indegree - outdegree" of anyone else will be less than n-1, indicating the value of town judge is unique.
