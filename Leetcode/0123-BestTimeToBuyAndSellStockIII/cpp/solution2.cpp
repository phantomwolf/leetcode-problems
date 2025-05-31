class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // From right to left
        vector<int> rightProfits(n+1, 0);
        int maxPrice = prices[n-1];
        for (int i = n-2; i >= 0; i--) {
            rightProfits[i] = max(rightProfits[i+1], maxPrice-prices[i]);
            maxPrice = max(maxPrice, prices[i]);
        }
        // From left to right
        int result = 0;
        int minPrice = prices[0];
        int leftProfit = 0;
        for (int i = 1; i < n; i++) {
            leftProfit = max(leftProfit, prices[i]-minPrice);
            result = max(result, leftProfit + rightProfits[i+1]);
            minPrice = min(minPrice, prices[i]);
        }
        return result;
    }
};
