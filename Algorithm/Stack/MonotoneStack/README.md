# Monotonic Stack
A Monotonic Stack is a common data structure in computer science that maintains its elements in a specific order. Unlike traditional stacks, Monotonic Stacks ensure that elements inside the stack are arranged in an increasing or decreasing order based on their arrival time. 

![](monotonic-stack.png)

Monotonic Stacks can be broadly classified into two types:

1. Monotonic Increasing Stack
2. Monotonic Decreasing Stack

## Monotonic Increasing Stack
A **Monotonically Increasing Stack** is a stack where elements are placed in **increasing** order **from the bottom to the top**. Each new element added to the stack is **greater than or equal to** the one below it. If a new element is smaller, we remove elements from the top of the stack until we find one that is smaller or equal to the new element, or until the stack is empty. This ensures that the stack always stays in increasing order.

单调递增栈，即元素**从栈底到栈顶保持递增**的栈。每个即将入栈的元素，都必须**大于或等于栈顶元素**。如果条件不满足，那就必须持续退栈，直到即将入栈的元素大于或等于栈顶元素为止（或直到栈为空）。

## 