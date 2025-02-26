#include <algorithm>
#include <limits>
#include <vector>

using std::vector;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // Since nums1 has enough space, we can write the merge results from the end
    // to beginning This won't overwrite the original numbers in nums1
    int i = m - 1;
    int j = n - 1;
    for (int k = m + n - 1; k >= 0; k--) {
      int val1 = (i < 0) ? std::numeric_limits<int>::min() : nums1[i];
      int val2 = (j < 0) ? std::numeric_limits<int>::min() : nums2[j];
      if (val1 > val2) {
        nums1[k] = nums1[i];
        i--;
      } else {
        nums1[k] = nums2[j];
        j--;
      }
    }
  }
};
