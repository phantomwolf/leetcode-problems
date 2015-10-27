#include <algorithm>
#include <iostream>
#include <limits>
#include <cstdint>

using namespace std;


class Solution
{
public:
    inline int prev(const vector<int> &nums, int i, int end)
    {
        do {
            --i;
        } while (i >= end && nums[i] == nums[i + 1]);
        return i;
    }

    inline int next(const vector<int> &nums, int i, int end)
    {
        do {
            ++i;
        } while (i <= end && nums[i] == nums[i - 1]);
        return i;
    }

    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        if (nums.size() < 4)
            return res;
        // sort array
        sort(nums.begin(), nums.end());
        cout << "[";
        for (int i = 0; i < nums.size(); ++i) {
            cout << nums[i] << ",";
        }
        cout << "]" << endl;
        // 4Sum
        int length = nums.size();
        for (int i = 0; i < length - 3; i = next(nums, i, length - 4)) {
            for (int j = i + 1; j < length - 2; j = next(nums, j, length - 3)) {
                int objective = target - nums[i] - nums[j];
                int m = j + 1, n = length - 1;
                while (m < n) {
                    if (nums[m] + nums[n] < objective) {
                        m = next(nums, m, n);
                    } else if (nums[m] + nums[n] > objective) {
                        n = prev(nums, n, m);
                    } else {
                        res.push_back(vector<int>{nums[i], nums[j], nums[m], nums[n]});
                        m = next(nums, m, n);
                        n = prev(nums, n, m);
                    }
                }
            }
        }
        return res;
    }
};


int main(int argc, char *argv[])
{
    Solution s;

    vector<int> nums{1, 0, -1, 0, 0, -2, 2};
    int target = 0;

    vector<vector<int>> res = s.fourSum(nums, target);
    cout << "result: ";
    for (int i = 0; i < res.size(); ++i) {
        cout << "[";
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << ", ";
        }
        cout << "], ";
    }
    cout << endl;

    return 0;
}
