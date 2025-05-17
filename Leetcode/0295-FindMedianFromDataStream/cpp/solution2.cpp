#include <functional>
#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;

class MedianFinder {
 private:
  priority_queue<int, vector<int>, std::less<int>> leftHeap;
  int leftSize = 0;
  priority_queue<int, vector<int>, std::greater<int>> rightHeap;
  int rightSize = 0;

  // rightSize+1 >= leftSize >= rightSize
  void balance() {
    while (leftSize >= rightSize + 1) {
      int val = leftHeap.top();
      leftHeap.pop();
      leftSize--;
      rightHeap.push(val);
      rightSize++;
    }
    while (leftSize < rightSize) {
      int val = rightHeap.top();
      rightHeap.pop();
      rightSize--;
      leftHeap.push(val);
      leftSize++;
    }
  }

 public:
  MedianFinder() {}

  void addNum(int num) {
    if (leftHeap.empty() || num <= leftHeap.top()) {
      leftHeap.push(num);
      leftSize++;
    } else {
      rightHeap.push(num);
      rightSize++;
    }
    this->balance();
  }

  double findMedian() {
    if ((this->leftSize + this->rightSize) % 2 == 0) {
      return (double)(leftHeap.top() + rightHeap.top()) / 2;
    }
    return leftHeap.top();
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */