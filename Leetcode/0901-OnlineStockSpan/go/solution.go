type StockSpanner struct {
	// Stores indexes of price history
	stack     [][]int // [index, price] pairs
	nextIndex int
}

func Constructor() StockSpanner {
	return StockSpanner{
		stack:     [][]int{},
		nextIndex: 0,
	}
}

func (this *StockSpanner) Next(price int) int {
	// In order to get Previous Greater Element, keep popping elements smaller than or equal to price
	for len(this.stack) > 0 && this.stack[len(this.stack)-1][1] <= price {
		this.stack = this.stack[0 : len(this.stack)-1]
	}
	var result int
	// If no Previous Greater Element found
	if len(this.stack) == 0 {
		result = this.nextIndex + 1
	} else {
		result = this.nextIndex - this.stack[len(this.stack)-1][0]
	}
	// Push new element to stack
	this.stack = append(this.stack, []int{this.nextIndex, price})
	this.nextIndex++
	return result
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Next(price);
 */