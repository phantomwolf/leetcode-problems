#include <iostream>
#include <vector>
#include <limits>

using namespace std;


class Solution
{
public:
    // 让数组按照谷值、峰值、谷值、峰值...的顺序排列，
    // 并返回一个新的长度
    size_t filter_valley_peak(vector<int> &prices)
    {
        size_t new_len    = 0;
        size_t length = prices.size();
        bool   incr       = false;
        for (size_t i = 1; i < length; ++i) {
            if (incr && prices[i - 1] > prices[i]) {
                prices[new_len++] = prices[i - 1];
                incr = false;
            } else if (!incr && prices[i - 1] < prices[i]) {
                prices[new_len++] = prices[i - 1];
                incr = true;
            }
        }
        if (incr) {
            prices[new_len++] = prices[length - 1];
        }
        return new_len;
    }

    int maxProfit(int k, vector<int> &prices)
    {
        size_t length = prices.size();
        if (length < 2 || k == 0)
            return 0;
        // 求出所有谷值、峰值
        length = filter_valley_peak(prices);
        if (k >= length) {
            int max_profit = 0;
            for (int i = 0; i < length; i += 2) {
                max_profit += prices[i + 1] - prices[i];
            }
            return max_profit;
        }
        // 令profit[i][j]为第
        vector<vector<int>> profit(k + 1, vector<int>(length + 1));
        for (int i = 0; i <= k; ++i) {
            profit[i][0] = 0;
        }
        for (int j = 0; j <= length; ++j) {
            profit[0][j] = 0;
        }
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= length; ++j) {
                profit[i][j] = profit[i][j - 1];
                for (int m = 0; m < j; ++m) {
                    int tmp = prices[j - 1] - prices[m] + profit[i - 1][m];
                    if (profit[i][j] < tmp)
                        profit[i][j] = tmp;
                }
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
