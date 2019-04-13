#include <vector>
#include <iostream>
#include <limits>

using namespace std;


class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        double max = numeric_limits<int>::min();
        double min = numeric_limits<int>::max();
        for (int i : nums) {
            if (i > max)
                max = i;
            if (i < min)
                min = i;
        }

        double prev_mid = max;
        double error = numeric_limits<int>::max();
        cout << "trying: ";
        while (error > 0.00001) {
            double mid = (max + min) * 0.5;
            cout << mid << ", ";
            if (this->check(nums, mid, k)) {
                min = mid;
            } else {
                max = mid;
            }
            error = prev_mid - mid;
            error = (error > 0) ? error : -error;
            prev_mid = mid;
        }
        return min;
    }


protected:
    bool check(vector<int> &nums, double mid, int k)
    {
        double sum = 0, prev = 0, min_sum = 0;
        for (int i = 0; i < k; ++i)
            sum += nums[i] - mid;
        if (sum >= 0)
            return true;

        vector<int>::size_type length = nums.size();
        for (int i = k; i < length; ++i) {
            sum += nums[i] - mid;
            prev += nums[i - k] - mid;
            min_sum = (prev < min_sum) ? prev : min_sum;
            if (sum >= min_sum)
                return true;
        }
        return false;
    }
};


int main(int argc, char *argv[])
{
    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;
    Solution s;

    cout << s.findMaxAverage(nums, k) << endl;

    return 0;
}
