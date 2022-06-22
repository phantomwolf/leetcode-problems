# 31.Next Permutation 
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column::

```
    1,2,3 → 1,3,2
    3,2,1 → 1,2,3
    1,1,5 → 1,5,1
```

## Analysis
### Base case
When the input array is sorted by descending order, just reverse the array. Time complexity: O(n)

### General case
The next permutation of [1,2,5,3,1] is [1,3,1,2,5].

[1,2,5,3,1] can be divided into 2 parts:

```
    [1,2, | 5,3,1]
```

You can see the 2nd part is in descending order. Now in the 2nd part of the array, find the **smallest** number which is **greater** than the **rightmost number**(in this case it's 2) of the 1st part, which is 3. 3 is greater than 2, and in the 2nd part there's no smaller number which is larger than 2.

Swap 3 and 2. Now the array will be like:

```
    [1,3, | 5,2,1]
```

Note that the 2nd part is still in descending order. **Reverse** the 2nd part and we'll get the correct result:

```
    [1,3, | 1,2,5]
```

Time complexity: O(n)