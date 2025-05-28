class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    // Edge case
    if (prices.size() == 1) {
      return 0;
    }
    // Result
    int res = 0;
    int i = 1;
    while (i < prices.size()) {
      // Find a valley price
      while (i < prices.size() && prices[i - 1] >= prices[i]) {
        i++;
      }
      int valley = prices[i - 1];
      // Find a peak price
      while (i < prices.size() && prices[i - 1] <= prices[i]) {
        i++;
      }
      int peak = prices[i - 1];
      // Aggregate profit
      res += peak - valley;
    }
    return res;
  }
};