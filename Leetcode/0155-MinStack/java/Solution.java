public class MinStack {
    private Deque<Integer> mainStack = new ArrayDeque<>();
    private Deque<Integer> monoStack = new ArrayDeque<>();

    public MinStack() {
        
    }

    public void push(int val) {
        mainStack.push(val);
        if (monoStack.isEmpty() || monoStack.peek() >= val) {
            monoStack.push(val);
        }
    }

    public void pop() {
        int val = mainStack.pop();
        if (monoStack.peek() == val) {
            monoStack.pop();
        }
    }
    
    public int top() {
        return mainStack.peek();
    }
    
    public int getMin() {
        return monoStack.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */