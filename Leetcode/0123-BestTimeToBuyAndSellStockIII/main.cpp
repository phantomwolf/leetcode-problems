#include <iostream>
#include <vector>
#include <limits>

using namespace std;


class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy1, buy2, sell1, sell2;
        int length = prices.size();
        buy1 = buy2 = numeric_limits<int>::min();
        sell1 = sell2 = 0;
        for (int i = 0; i < length; ++i) {
            if (buy1 < -prices[i]) {
                buy1 = -prices[i];
            }
            if (sell1 < buy1 + prices[i]) {
                sell1 = buy1 + prices[i];
            }
            if (buy2 < sell1 - prices[i]) {
                buy2 = sell1 - prices[i];
            }
            if (sell2 < buy2 + prices[i]) {
                sell2 = buy2 + prices[i];
            }
        }
        return max(sell1, sell2);
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    vector<int> prices{2, 1, 2, 0, 1};
    cout << "max profit: " << s.maxProfit(prices) << endl;

    return 0;
}
