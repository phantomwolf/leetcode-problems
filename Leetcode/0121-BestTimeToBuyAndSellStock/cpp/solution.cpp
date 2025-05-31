#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) {
            return 0;
        }

        int result = 0;
        int minPrice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            int profit = prices[i] - minPrice;
            result = max(result, profit);
            minPrice = min(minPrice, prices[i]);
        }
        return result;
    }
};