#include <iostream>
#include <vector>
#include <limits>

using namespace std;


class Solution
{
public:
    size_t adequate_transactions(vector<int> &prices)
    {
        size_t length = prices.size();
        int max_profit = 0;
        bool incr = false;
        int valley;
        for (int i = 1; i < length; ++i) {
            if (incr && prices[i - 1] > prices[i]) {
                max_profit += prices[i - 1] - valley;
                incr = false;
            } else if (!incr && prices[i - 1] < prices[i]) {
                valley = prices[i - 1];
                incr = true;
            }
        }
        if (incr)
            max_profit += prices[length - 1] - valley;
        return max_profit;
    }

    int maxProfit(int k, vector<int> &prices)
    {
        size_t length = prices.size();
        if (length < 2 || k == 0)
            return 0;
        if (k > length / 2)
            return adequate_transactions(prices);

        vector<vector<int>> profit(k + 1, vector<int>(length + 1));
        for (int i = 0; i <= k; ++i) {
            profit[i][0] = 0;
        }
        for (int j = 0; j <= length; ++j) {
            profit[0][j] = 0;
        }
        for (int i = 1; i <= k; ++i) {
            int prev_diff = numeric_limits<int>::min();
            for (int j = 1; j <= length; ++j) {
                prev_diff = max(prev_diff, profit[i - 1][j - 1] - prices[j - 1]);
                profit[i][j] = max(profit[i][j - 1], prices[j - 1] + prev_diff);
            }
        }
        return profit[k][length];
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    //vector<int> prices{1, 2, 4, 2, 5, 7, 2, 4, 9, 0, 9};
    //int k = 4;
    //vector<int> prices{0, 8, 5, 7, 4, 7};
    //int k = 2;
    //vector<int> prices{10, 22, 5, 75, 65, 80};
    //int k = 2;
    vector<int> prices{1,4,2,7};
    int k = 2;
    cout << "max profit: " << s.maxProfit(k, prices) << endl;

    return 0;
}
