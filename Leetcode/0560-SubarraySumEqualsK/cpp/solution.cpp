class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    vector<int> prefixSum(nums.size(), 0);
    prefixSum[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      prefixSum[i] = prefixSum[i - 1] + nums[i];
    }

    int res = 0;
    unordered_map<int, int> count;
    // Indicates empty subset
    count[0] = 1;
    for (int i = 0; i < prefixSum.size(); i++) {
      auto it = count.find(prefixSum[i] - k);
      if (it != count.end()) {
        res += it->second;
      }
      count[prefixSum[i]]++;
    }
    return res;
  }
};