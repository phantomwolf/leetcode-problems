#include <vector>
#include <iostream>

using namespace std;


class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int max_profit = 0;
        int length = prices.size();
        if (length < 2)
            return 0;
        int min_price = prices[0];
        for (int i = 1; i < length; ++i) {
            int profit = prices[i] - min_price;
            if (profit > max_profit)
                max_profit = profit;
            if (prices[i] < min_price)
                min_price = prices[i];
        }
        return max_profit;
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    vector<int> prices{7, 1, 5, 3, 6, 4};
    cout << "max profit: " << s.maxProfit(prices) << endl;

    return 0;
}
