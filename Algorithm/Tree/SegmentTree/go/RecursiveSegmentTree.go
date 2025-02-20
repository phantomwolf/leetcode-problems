package main

import (
	"fmt"
)

type RecursiveSegmentTree struct {
	tree []int
	lazy []int
	size int
}

func NewRecursiveSegmentTree(nums []int) *RecursiveSegmentTree {
	st := &RecursiveSegmentTree{
		tree: make([]int, len(nums)*4),
		lazy: make([]int, len(nums)*4),
		size: len(nums),
	}
	st.build(nums, 0, len(nums)-1, 1)
	return st
}

/*
 * Builds a segment tree
 * nums: array of numbers to be built into segment tree
 * start: The starting index of the segment (inclusive) that the current node p represents in the original array.
 * to: The ending index of the segment (inclusive) that the current node p represents in the original array.
 * p: The index of the current node in the segment tree array tree[].
 */
func (st *RecursiveSegmentTree) build(nums []int, start int, to int, p int) {
	if start == to {
		// leaf
		st.tree[p] = nums[start]
		return
	}
	// Recursively build left and right subtrees
	mid := start + (to-start)/2
	st.build(nums, start, mid, p*2)
	st.build(nums, mid+1, to, p*2+1)
	st.tree[p] = st.tree[p*2] + st.tree[p*2+1]
}

func (st *RecursiveSegmentTree) Size() int {
	return st.size
}

func (st *RecursiveSegmentTree) Query(left int, right int) int {
	return st.query(left, right, 0, st.size-1, 1)
}

/**
 * left: left boundary of the query range
 * right: right boundary of the query range
 * start: The starting index of the segment (inclusive) that the current node p represents in the original array.
 * to: The ending index of the segment (inclusive) that the current node p represents in the original array.
 * p: The index of the current node in the segment tree array tree[].
 */
func (st *RecursiveSegmentTree) query(left int, right int, start int, to int, p int) int {
	if left <= start && to <= right {
		// Current node's range is a subset of the query range [left, right]
		return st.tree[p]
	}
	mid := start + (to-start)/2
	sum := 0
	if left <= mid {
		sum += st.query(left, right, start, mid, p*2)
	}
	if right >= mid+1 {
		sum += st.query(left, right, mid+1, to, p*2+1)
	}
	return sum
}

/**
 * Add "change" to all elements within range [left, right] in the original array
 * left: left boundary of the update range
 * right: right boundary of the update range
 * change: the diff to be added to elements
 */
func (st *RecursiveSegmentTree) Update(left int, right int, change int) {
	st.update(left, right, change, 0, st.size-1, 1)
}

/**
 * Add "change" to all elements within range [left, right] in the original array
 * left: left boundary of the update range
 * right: right boundary of the update range
 * change: the diff to be added to elements
 * start: The starting index of the segment (inclusive) that the current node p represents in the original array.
 * to: The ending index of the segment (inclusive) that the current node p represents in the original array.
 * p: The index of the current node in the segment tree array tree[].
 */
func (st *RecursiveSegmentTree) update(left int, right int, change int, start int, to int, p int) {
	// If [start, to] is within update range [left, right], update current node and set lazy propogation
	if left <= start && to <= right {
		// Each element should plus "change". Since node p's value is the sum of elements in range [start, to],
		// its value should increase (to - start + 1) * change
		st.tree[p] += (to - start + 1) * change
		st.lazy[p] += change
		return
	}
	// Continue if [start, to] partially intersects with [left, right]
	mid := start + (to-start)/2
	if st.lazy[p] != 0 && start != to {
		// If current node already has lazy propogation, update the values and lazy propogations of both its children
		// left child: [start, mid]
		st.tree[p*2] += st.lazy[p] * (mid - start + 1)
		// right child: [mid+1, to]
		st.tree[p*2+1] += st.lazy[p] * (to - mid)
		// Pass the lazy propagation to its children
		st.lazy[p*2] += st.lazy[p]
		st.lazy[p*2+1] += st.lazy[p]
		// Clear current node's lazy propagation
		st.lazy[p] = 0
	}
	if left <= mid {
		// If [left, right] intersects with [start, mid]
		st.update(left, right, change, start, mid, p*2)
	}
	if mid+1 <= right {
		st.update(left, right, change, mid+1, to, p*2+1)
	}
	st.tree[p] = st.tree[p*2] + st.tree[p*2+1]
}

func (st *RecursiveSegmentTree) Print() {
	fmt.Println("Segment tree:")
	st.print(0, st.size-1, 1)
}

func (st *RecursiveSegmentTree) print(start int, to int, p int) {
	fmt.Printf("tree[%d]=%d, [%d:%d], lazy=%d\n", p, st.tree[p], start, to, st.lazy[p])
	if start == to {
		return
	}
	mid := start + (to-start)/2
	st.print(start, mid, p*2)
	st.print(mid+1, to, p*2+1)
}

func main() {
	nums := []int{0, 1, 3, 5, -2, 3}
	st := NewRecursiveSegmentTree(nums)
	st.Print()
	// Query
	rangeSum := st.Query(3, 3)
	fmt.Println(rangeSum)
	// Range update
	st.Update(0, 2, 3)
	st.Print()
}
