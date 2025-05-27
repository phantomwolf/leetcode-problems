class Solution {
 public:
  void sortColors(vector<int>& nums) {
    // i: next writing position for elements smaller than mid
    int i = 0;
    // j: scanning position
    int j = 0;
    // k: next writing position for elements greater than mid
    int k = nums.size() - 1;
    // Index for scanning the array
    while (j <= k) {
      if (nums[j] < 1) {
        std::swap(nums[i], nums[j]);
        i++;
        j++;
      } else if (nums[j] > 1) {
        std::swap(nums[j], nums[k]);
        k--;
      } else {
        j++;
      }
    }
  }
};