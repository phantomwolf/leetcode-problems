#include <functional>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using std::cout;
using std::endl;
using std::priority_queue;
using std::unordered_map;
using std::vector;

template <class T, class S, class C>
S& Container(priority_queue<T, S, C>& q) {
  struct HackedQueue : private priority_queue<T, S, C> {
    static S& Container(priority_queue<T, S, C>& q) {
      return q.*&HackedQueue::c;
    }
  };
  return HackedQueue::Container(q);
}

class MedianFinder {
 private:
  priority_queue<int, vector<int>, std::less<int>> leftHeap;
  int leftSize = 0;
  priority_queue<int, vector<int>, std::greater<int>> rightHeap;
  int rightSize = 0;
  unordered_map<int, int> lazy;

  // rightSize+1 >= leftSize >= rightSize
  void balance() {
    while (leftSize >= rightSize + 1) {
      int val = leftHeap.top();
      leftHeap.pop();
      leftSize--;

      prune(leftHeap);

      rightHeap.push(val);
      rightSize++;
    }
    while (leftSize < rightSize) {
      int val = rightHeap.top();
      rightHeap.pop();
      rightSize--;

      prune(rightHeap);

      leftHeap.push(val);
      leftSize++;
    }
  }

  template <typename T, typename Container = std::vector<T>,
            typename Compare = std::less<T>>
  void prune(priority_queue<T, Container, Compare>& heap) {
    while (heap.size() > 0) {
      if (lazy[heap.top()] > 0) {
        lazy[heap.top()]--;
        heap.pop();
        continue;
      }
      return;
    }
  }

 public:
  MedianFinder() {}

  void addNum(int num) {
    cout << "addNum " << num << endl;
    if (leftHeap.empty() || num <= leftHeap.top()) {
      leftHeap.push(num);
      leftSize++;
    } else {
      rightHeap.push(num);
      rightSize++;
    }
    balance();
  }

  // Suppose num is in the heaps
  void delNum(int num) {
    cout << "delNum " << num << endl;
    lazy[num]++;
    if (num <= leftHeap.top()) {
      leftSize--;
      prune(leftHeap);
    } else {
      rightSize--;
      prune(rightHeap);
    }
    balance();
  }

  double findMedian() {
    if ((leftSize + rightSize) % 2 == 0) {
      return (double)(leftHeap.top() + rightHeap.top()) / 2;
    }
    return leftHeap.top();
  }

  void print() {
    cout << "left:  ";
    vector<int>& arr1 = Container(leftHeap);
    for (auto num : arr1) {
      cout << num << " ";
    }
    cout << endl << "right: ";
    vector<int>& arr2 = Container(rightHeap);
    for (auto num : arr2) {
      cout << num << " ";
    }
    cout << endl;
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(int argc, char* argv[]) {
  MedianFinder mf;
  mf.addNum(1);
  mf.addNum(3);
  mf.addNum(5);
  mf.addNum(2);
  mf.addNum(4);
  mf.print();
  cout << "median: " << mf.findMedian() << endl;
  mf.delNum(2);
  mf.print();
  cout << "median: " << mf.findMedian() << endl;
  mf.delNum(3);
  mf.print();
  cout << "median: " << mf.findMedian() << endl;
}