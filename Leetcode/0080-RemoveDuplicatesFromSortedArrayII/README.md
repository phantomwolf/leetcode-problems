# 80. Remove Duplicates from Sorted Array II
Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}

If all assertions pass, then your solution will be accepted.

## Example 1:

Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

## Example 2:

Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]
Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

## Constraints:

    1 <= nums.length <= 3 * 104
    -104 <= nums[i] <= 104
    nums is sorted in non-decreasing order.

# Solution
与26题类似，同样设置i指针扫描整个数组，j指针为写入位置。当满足以下任一条件时，将nums[i]写入nums[j]并j++：

1. 当遇到新的独特元素时：nums[i] != nums[i-1]
2. 遇到重复元素，但尚未写入2个时。因为遇到了重复元素，即nums[i] == nums[i-1]，那么nums[i-1]必然在上一轮循环中被写入到nums[j-1]了。此时，如果nums[j-2] == nums[i]，那就说明nums[j-1]和nums[j-2]的值一样，都是nums[i]，表明已经写入了两个nums[i]，此时不应再写入nums[i]；如果j-2 < 0或者nums[j-2] != nums[i]，那就说明目前只写入了一个nums[i]，还能再写入一个，即`nums[j] = nums[i]; j++`。