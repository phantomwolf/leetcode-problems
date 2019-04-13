#include <vector>
#include <iostream>
#include <limits>

using namespace std;


class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int n = nums.size();
        double max_avg = numeric_limits<int>::min();

        int init_sum = 0;
        for (int i = 0; i < k - 1; ++i) {
            init_sum += nums[i];
        }


        while (k <= n) {
            init_sum += nums[k - 1];
            int sum = init_sum;
            int max_sum = sum;
            for (int i = k; i < n; ++i) {
                sum = sum - nums[i - k] + nums[i];
                if (max_sum < sum) 
                    max_sum = sum;
            }
            double avg = max_sum / (double)k;
            if (max_avg < avg)
                max_avg = avg;
            ++k;
        }
        return max_avg;
    }
};


int main()
{
    Solution s;
    vector<int> nums = {-1};
    int k = 1;

    cout << "max averge: " << s.findMaxAverage(nums, k) << endl;
}
