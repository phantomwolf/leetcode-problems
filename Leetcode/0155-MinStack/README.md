# 155. Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

* `MinStack()` initializes the stack object.
* `void push(int val)` pushes the element val onto the stack.
* `void pop()` removes the element on the top of the stack.
* `int top()` gets the top element of the stack.
* `int getMin()` retrieves the minimum element in the stack.
* You must implement a solution with O(1) time complexity for each function.

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2

Constraints:

* -2^31 <= val <= 2^31 - 1
* Methods pop, top and getMin operations will always be called on non-empty stacks.
* At most 3 * 104 calls will be made to push, pop, top, and getMin.

## Solution
Most of the methods are the same as an ordinary stack, so we can introduce a stack to implement those operations.

The only exception is `getMin()` needs to return the min value in O(1) time. Here we can use the monotonic stack technique:

* create another stack `monoStack` and only push when `val <= monoStack.peek()`.
* when the poped element is the same as `monoStack.peek()`, do `monoStack.pop()` as well.
* when `getMin()`, just return `monoStack.peek()`.

**Why does it work?**

1. When pushing the first value `val1`, of course `val1` is the min value, so we push `val1` into `monoStack` as well: `monoStack.push(val1)`.
2. When pushing the second value `val2`:
    a. If `val2 > val1`, `val2` has no effect on the min value. This is because `val2` is above `val1` in the main stack, and `val2` will be poped before `val1`. And `getMin()` will always prefer `val1` over `val2` as long as `val1` is still in the stack. So we won't push `val2` into `monoStack`.
    b. If `val2 < val1`, `val2` is the new min value, so `monoStack.push(val2)`.
    c. If `val2 == val1`, to make the codes simple, it's recommended to push `val2` into `monoStack` as well, so that we don't have to track the count of duplicated elements when poping.
