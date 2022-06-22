# 1642. Furthest Building You Can Reach
You are given an integer array heights representing the heights of buildings, some bricks, and some ladders.

You start your journey from building 0 and move to the next building by possibly using bricks or ladders.

While moving from building i to building i+1 (0-indexed),

- If the current building's height is greater than or equal to the next building's height, you do not need a ladder or bricks.
- If the current building's height is less than the next building's height, you can either use one ladder or (h[i+1] - h[i]) bricks.

Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.

## Example 1:

```
Input: heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
Output: 4

Explanation: Starting at building 0, you can follow these steps:
- Go to building 1 without using ladders nor bricks since 4 >= 2.
- Go to building 2 using 5 bricks. You must use either bricks or ladders because 2 < 7.
- Go to building 3 without using ladders nor bricks since 7 >= 6.
- Go to building 4 using your only ladder. You must use either bricks or ladders because 6 < 9.
It is impossible to go beyond building 4 because you do not have any more bricks or ladders.
```

## Example 2

```
Input: heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2
Output: 7
```

## Example 3

```
Input: heights = [14,3,19,3], bricks = 17, ladders = 0
Output: 3
```

## Constraints:
- 1 <= heights.length <= 105
- 1 <= heights[i] <= 106
- 0 <= bricks <= 109
- 0 <= ladders <= heights.length

# Solution
由于梯子可以爬过任何高度差，所以在可到达的范围内，将梯子放在最陡峭的地方价值最大。问题转化为，如何在当前滑动窗口里，保存最大的ladders个元素。

## Min heap solution
为了达到将梯子用在高度差最大的地方的目的，我们先将梯子用尽，之后如果遇到了更大的高度差，再将梯子替换过来。

用一个最小堆保存梯子所在位置的高度差。从左向右开始扫描，首先把梯子用尽，将这些高度差存入最小堆，堆顶就是使用梯子的高度差里最小的一个。

继续向右扫描，如果遇到比堆顶元素更大的高度差，在砖头足够的前提下，我们可以将梯子移动到这个新位置，用砖块填满之前的梯子所在的位置，来获得一个更好的结果，直到砖块不够。

## Max heap solution
为了达到将梯子用在高度差最大的地方的目的，我们优先将砖块用尽，砖块不够时，我们试着拿出一个梯子，放在当前扫描范围内最大的高度差的位置，最大限度地恢复砖块的数量。持续前进，直到梯子用尽且砖块也不足以前进为止。

用一个最大堆，保存扫描过的所有使用砖块的高度差。当砖块数量不足以前进时，堆顶元素是目前为止最大的高度差，将梯子放在此处，从而取回该处的砖块。继续前进，直到梯子用完，砖块数量不够为止。