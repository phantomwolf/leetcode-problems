package main

import "fmt"

type IterativeSegmentTree struct {
	tree []int
	size int
}

func NewIterativeSegmentTree(nums []int) *IterativeSegmentTree {
	st := &IterativeSegmentTree{
		// tree uses array size of 2*N. N is the size of nums array
		tree: make([]int, len(nums)*2),
		size: len(nums),
	}
	st.build(nums)
	return st
}

func (st *IterativeSegmentTree) build(nums []int) {
	// Leaf nodes reside in tree[n, 2*n]
	for i, j := len(nums), 0; i < 2*len(nums); i, j = i+1, j+1 {
		st.tree[i] = nums[j]
	}
	// Build parent nodes bottom-up
	for i := len(nums) - 1; i > 0; i-- {
		st.tree[i] = st.tree[2*i] + st.tree[2*i+1]
	}
}

// Returns the size of the original nums array
func (st *IterativeSegmentTree) Size() int {
	return st.size
}

/**
 * Update the single value in the tree
 * index: the index of the value to be updated in the original array
 * value: the new value
 */
func (st *IterativeSegmentTree) Update(index int, value int) {
	// Because leaf nodes reside in tree[n, 2*n], nums[0] == tree[n]
	p := index + st.Size()
	st.tree[p] = value
	for p > 0 {
		var left, right int
		if p%2 == 0 {
			// If nums[index] is the left child of its parent
			left = p
			right = p + 1
		} else {
			// If nums[index] is the right child of its parent
			left = p - 1
			right = p
		}
		st.tree[left/2] = st.tree[left] + st.tree[right]
		// Go up
		p = left / 2
	}
}

// Returns the sum of nums[left, right], inclusive
func (st *IterativeSegmentTree) Query(left int, right int) int {
	// st.tree[left + n] == nums[left]
	left += st.Size()
	right += st.Size()
	sum := 0
	for left <= right {
		// If st.tree[left] is the right child of its parent, add its value to sum and exclude it
		if left%2 == 1 {
			sum += st.tree[left]
			left++
		}
		// If st.tree[right] is the left child of its parent, add its value to sum and exclude it
		if right%2 == 0 {
			sum += st.tree[right]
			right--
		}
		// Go up
		left /= 2
		right /= 2
	}
	return sum
}

func (st *IterativeSegmentTree) Print() {
	fmt.Printf("%v\n", st.tree)
}

func main() {
	nums := []int{0, 1, 3, 5, -2, 3}
	st := NewIterativeSegmentTree(nums)
	st.Print()
}
