#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    inline int abs(int n) {
        return (n < 0) ? -n : n;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        int closest = target + numeric_limits<int>::max();
        sort(nums.begin(), nums.end());
        for (int i=0; i < nums.size(); ++i) {
            int left = i+1, right = nums.size()-1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (this->abs(sum - target) < this->abs(closest - target)) {
                    closest = sum;
                }
                if (sum == target) {
                    return sum;
                } else if (sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return closest;
    }
};

int main()
{
    Solution s;
    vector<int> nums{-1, 2, 1, -4};
    int target = 1;
    int res = s.threeSumClosest(nums, target);
    cout << "Result: " << res << endl;
    return 0;
}
