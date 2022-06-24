# Find all subsets of an array
## Backtracking
Write a recursive method which accepts the array, the current index, and the current subset as parameters:

1. Base case: when index reaches the end of the array, add current subset to the result
2. For each array[index], we have 2 choices: adding it to the current subset or not.

```java
private void findSubsets(int[] nums, int index, List<Integer> subset, int sum) {
    // base case
    if (index == nums.length) {
        subsets.add(subset);
        subsetSums.add(sum);
        return;
    }
    // Choice 1: don't add nums[index] to the subset
    findSubsets(nums, index + 1, new ArrayList<>(subset), sum);
    // Choice 2: add nums[index] to the subset
    subset.add(nums[index]);
    sum += nums[index];
    findSubsets(nums, index + 1, new ArrayList<>(subset), sum);
}
```

## Bit manipulation
This approach only applies to arrays with limited length.

To make it easier to understand, let's consider the following 8-bit integer variable:

```java
char mask = 0;
```

If we increment it to 255, it's going to be: 0, 1, 2, 3, ..., 254, 255. If we write these numbers in their binary forms:

```
    0000 0000
    0000 0001
    0000 0010
    0000 0011
    0000 0100
    ...
    1111 1110
    1111 1111
```
These binary numbers all have 8 bits. Suppose we have an array with a length of 8. We can associate each bit with an index of the array. Let's define:

1. The least significant digit is associated with index 0
2. If a bit is 1, the corresponding number in the array should be added to the current subset; if 0, the corresponding number shouldn't be added.

For example, for array `{1, 3, 5, 7, 11, 13, 17, 19}`, if `mask` is `0000 0011(3)`, the current subset should be `{1, 3}`.

How do we write a program to get all these subsets? We keep incrementing `mask` to `1 << array.length`(exclusive). For each `mask`, we test each of its bit. If a bit is 1, the corresponding element should be added to the subset.

```java
for (int mask = 0; mask < (1 << nums.length); mask++) {
    List<Integer> subset = new ArrayList<>();
    int sum = 0;
    for (int j = 0; j < nums.length; j++) {
        if ((mask & (1 << j)) != 0) {
            subset.add(nums[j]);
            sum += nums[j];
        }
    }
    subsets.add(subset);
    subsetSums.add(sum);
}
```

In the code above, the value `1 << j` will be like:

```
    0000 0001
    0000 0010
    0000 0100
    0000 1000
    ....
    0100 0000
    1000 0000
```

If we do bitwise AND between `mask` and `1 << j`, we'll know if a bit is 1 or not.
