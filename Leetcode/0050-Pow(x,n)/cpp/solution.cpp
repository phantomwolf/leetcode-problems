#include <unordered_map>

using namespace std;

class Solution {
 public:
  double myPow(double x, int n) {
    unordered_map<int, double> map;
    return myPowRecursive(x, n, map);
  }

  double myPowRecursive(double x, int n, unordered_map<int, double>& map) {
    // Base case
    if (n == 0) {
      return 1;
    } else if (n == 1) {
      return x;
    } else if (n == -1) {
      return 1.0 / x;
    }
    // Return value in cache
    auto iter = map.find(n);
    if (iter != map.end()) {
      return iter->second;
    }
    double result =
        myPowRecursive(x, n / 2, map) * myPowRecursive(x, n - n / 2, map);
    // Save result into cache
    map[n] = result;
    return result;
  }
};