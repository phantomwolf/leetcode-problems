public class MedianFinder {
    private PriorityQueue<Integer> leftHeap;
    private PriorityQueue<Integer> rightHeap;

    public MedianFinder() {
        // max heap
        this.leftHeap = new PriorityQueue<>((a, b) -> b - a);
        // min heap
        this.rightHeap = new PriorityQueue<>();
    }

    public void addNum(int num) {
        if (leftHeap.isEmpty() || num <= leftHeap.peek()) {
            leftHeap.add(num);
        } else {
            rightHeap.add(num);
        }
        balance();
    }

    public double findMedian() {
        if (leftHeap.size() == rightHeap.size()) {
            return (leftHeap.peek()+rightHeap.peek()) / 2.0;
        }
        return leftHeap.peek();
    }

    private void balance() {
        while (leftHeap.size() > rightHeap.size()+1) {
            int val = leftHeap.remove();
            rightHeap.add(val);
        }
        while (leftHeap.size() < rightHeap.size()) {
            int val = rightHeap.remove();
            leftHeap.add(val);
        }
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */