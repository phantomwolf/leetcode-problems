#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = numeric_limits<int>::min();
        int sell1 = 0;
        int buy2 = numeric_limits<int>::min();
        int sell2 = 0;
        for (int price : prices) {
            buy1 = max(buy1, -price);
            sell1 = max(sell1, buy1+price);
            buy2 = max(buy2, sell1-price);
            sell2 = max(sell2, buy2+price);
        }
        return max(sell1, sell2);
    }
};
