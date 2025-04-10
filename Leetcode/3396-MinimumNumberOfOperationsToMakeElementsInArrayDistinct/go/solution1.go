func minimumOperations(nums []int) int {
	// Track the number of each value
	count := make([]int, 101)
	duplicates := 0
	// Scan the array to record the numbers of each element
	for _, v := range nums {
		count[v]++
		if count[v] == 2 {
			duplicates++
		}
	}
	// Keep removing elements until all elements are distinct
	result := 0
	index := 0
	for duplicates > 0 && index < len(nums) {
		for i := 0; i < 3 && index < len(nums); i++ {
			count[nums[index]]--
			if count[nums[index]] == 1 {
				duplicates--
			}
			index++
		}
		result++
	}
	return result
}

/* Verification
Input: nums = [1,2,3,4,2,3,3,5,7]
Output: 2

         0  1  2  3  4  5  6  7
count = [0, 1, 2, 3, 1, 1, 0, 1], duplicates = 2

count[nums[0]]--, count[1]--
         0  1  2  3  4  5  6  7
count = [0, 0, 2, 3, 1, 1, 0, 1], duplicates = 2
count[nums[1]]--, count[2]--
         0  1  2  3  4  5  6  7
count = [0, 0, 1, 3, 1, 1, 0, 1], duplicates = 1
count[nums[2]]--, count[3]--
         0  1  2  3  4  5  6  7
count = [0, 0, 1, 2, 1, 1, 0, 1], duplicates = 1
result = 1

count[nums[3]]--, count[4]--
         0  1  2  3  4  5  6  7
count = [0, 0, 1, 2, 0, 1, 0, 1], duplicates = 1
count[nums[4]]--, count[2]--
         0  1  2  3  4  5  6  7
count = [0, 0, 0, 2, 0, 1, 0, 1], duplicates = 1
count[nums[5]]--, count[3]--
         0  1  2  3  4  5  6  7
count = [0, 0, 0, 1, 0, 1, 0, 1], duplicates = 0
result = 2

return result = 2
*/