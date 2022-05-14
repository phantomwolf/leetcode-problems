# 1094. Car Pooling
## Description
There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer capacity and an array trips where trips[i] = [numPassengers_i, from_i, to_i] indicates that the ith trip has numPassengers_i passengers and the locations to pick them up and drop them off are from_i and to_i respectively. The locations are given as the number of kilometers due east from the car's initial location.

Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

## Example 1

```
Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false
```

## Example 2

```
Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true
```

## Constraints

* 1 <= trips.length <= 1000
* trips[i].length == 3
* 1 <= numPassengers_i <= 100
* 0 <= from_i < to_i <= 1000
* 1 <= capacity <= 105

## 思路
如果用一个数组capacities表示每个公里处的剩余座位，问题就会变成多次更新子数组的值。用差分数组解决。

需要注意的是，[numPassengers_i, from_i, to_i] 对应的其实是[from_i, to_i)。假设车上共有30座位，从第3公里到第5公里30个乘客，从第5公里到第7公里30个乘客，这样是允许的。

