# 56. Merge Intervals
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

Constraints:

* 1 <= intervals.length <= 104
* intervals[i].length == 2
* 0 <= starti <= endi <= 104

## Solution: sort and merge
First, sort all intervals by their left index, so that all intervals with overlaps will be adjacent. We only need to compare and merge adjacent intervals.

There're 3 types of overlaps:

1. Interval 1 completely contains interval 2: `[1, 4]` and `[2, 3]`.
2. Interval 1 overlaps with interval 2: `[1, 3]` and `[2, 4]`.
3. Interval 1's end equals interval 2's start: `[1, 2]` and `[2, 4]`.

In all 3 cases, the merged new interval will be: `[interval1.start, max(interval1.end, interval2.end)]`.
