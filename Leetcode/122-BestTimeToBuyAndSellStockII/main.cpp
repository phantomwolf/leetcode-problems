#include <iostream>
#include <vector>


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

        // 若incr的初始值为true，而股票价格一开始的趋势是下降，
        // 那么会进入if/else第1个分支，然而此时bottom的值尚未计算出来，
        // 这显然是不对的。因此incr的初始值只能为false。
        bool incr = false;
        int bottom;
        for (int i = 1; i < length; ++i) {
            if (incr && prices[i - 1] > prices[i]) {
                // 拐点，由上升转为下降
                max_profit += prices[i - 1] - bottom;
                incr = false;
            } else if (!incr && prices[i - 1] < prices[i]) {
                // 拐点，由下降转为上升
                bottom = prices[i - 1];
                incr = true;
            }
        }
        // 若最后股票价格还在上升，那么在最后一天卖出之前买入的股票，
        // 利润是最大的。
        if (incr) {
            max_profit += prices[length - 1] - bottom;
        }
        return max_profit;
    }
};


int main()
{
    Solution s;
    vector<int> prices{1, 2, 3, 2, 1, 2};
    cout << "max profit: " << s.maxProfit(prices) << endl;

    return 0;
}
