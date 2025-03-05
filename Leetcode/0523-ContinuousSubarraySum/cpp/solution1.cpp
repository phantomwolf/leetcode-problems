#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    // Add pair (0, -1) to prefixSum, representing the boundary of the nums
    // array
    map[0] = -1;
    // Sum of nums[0:i], inclusive
    int currSum = 0;
    for (int i = 0; i < nums.size(); i++) {
      currSum += nums[i];
      // Try to find a prevSum in hash map, so that (currSum - prevSum)%k = 0,
      // and j - i = 2 Suppose currSum = x*k+a, 0 <= a < k, prevSum = y*k+b, 0
      // <= b < k, then:
      //      (x*k+a) - (y*k+b) = z*k
      // which means: a-b = k*(z-x+y), currSum%k = a, prevSum%k = b
      // Since all numbers involved are integers, a and b are both non-negative
      // and smaller than k, there's only 1 possibility:
      //      a = b
      // In conclusion, we only need to store the remainder in hash map and
      // query the same value again
      auto iter = map.find(currSum % k);
      if (iter == map.end()) {
        // If we couldn't find prevSum which has the same remainder of currSum,
        // save currSum%k to map
        map[currSum % k] = i;
        continue;
      }
      // If we find such a prevSum where prevSum%k = currSum%k, check if the
      // subarray length
      if (i - iter->second >= 2) {
        return true;
      }
      // No need to update the index of prevSum saved in map, because i will
      // always be larger than j. If we later meet another currSum%k which
      // already exists in map, j will likely to generate a better result
    }
    return false;
  }
};
