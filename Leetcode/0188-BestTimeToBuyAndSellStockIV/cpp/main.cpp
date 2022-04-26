#include <iostream>
#include <vector>
#include <limits>

using namespace std;


class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int length = prices.size();
        if (length == 0 || k == 0)
            return 0;
        vector<int> buy(k, numeric_limits<int>::min());
        vector<int> sell(k, 0);
        for (int i = 0; i < length; ++i) {
            if (buy[0] < -prices[i]) {
                buy[0] = -prices[i];
            } else if (sell[0] < buy[0] + prices[i]) {
                sell[0] = buy[0] + prices[i];
            }
            for (int j = 1; j < k; ++j) {
                if (buy[j] < sell[j - 1] - prices[i])
                    buy[j] = sell[j - 1] - prices[i];
                else if (sell[j] < buy[j] + prices[i])
                    sell[j] = buy[j] + prices[i];
            }
        }
        // return the maximum sell value
        int max_profit = sell[0];
        for (int i = 1; i < k; ++i) {
            if (max_profit < sell[i])
                max_profit = sell[i];
        }
        return max_profit;
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    vector<int> prices{1, 2, 4};
    int k = 2;
    cout << s.maxProfit(k, prices) << endl;

    return 0;
}
