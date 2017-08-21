#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int n = nums.size();
        long sum = nums[0];
        for (int i = 1; i < k; ++i) {
            sum += nums[i];
        }
        long max_sum = sum;
        for (int i = k; i < n; ++i) {
            sum = sum - nums[i - k] + nums[i];
            if (max_sum < sum)
                max_sum = sum;
        }
        return max_sum / (double)k;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums{-1};
    int k = 1;
    Solution s;
    cout << s.findMaxAverage(nums, k) << endl;

    return 0;
}
