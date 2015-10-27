#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution1 {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int length = nums.size();
        int boundary = length - 2;
        for (int i = 0; i < boundary; ++i) {
            int target = -nums[i];
            int left = i+1;
            int right = length-1;
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum < target) {
                    ++left;
                } else if (sum > target) {
                    --right;
                } else {
                    vector<int> triplet = {nums[i], nums[left], nums[right]};
                    res.push_back(triplet);
                    // skip duplicated numbers
                    while (left < right && nums[left] == triplet[1]) {
                        ++left;
                    }
                    while (left < right && nums[right] == triplet[2]) {
                        --right;
                    }
                }
            }
            while (i+1 < length && nums[i+1] == nums[i]) {
                ++i;
            }

        }
        return res;
    }
};

class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        if (nums.size() < 3)
            return res;
        sort(nums.begin(), nums.end());
        unordered_set<int> s;
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i != 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int target = -nums[i];
            s.clear();
            for (int j = i+1; j < nums.size(); ++j) {
                if (j != nums.size() - 1 && nums[j] == nums[j+1]) {
                    s.insert(nums[j]);
                    continue;
                }
                cout << i << ": " << nums[i] << ", " << j << ": " << nums[j] << endl;
                if (s.find(target - nums[j]) != s.end()) {
                    res.push_back(vector<int>{nums[i], target - nums[j], nums[j]});
                }
                s.insert(nums[j]);
            }
        }
        return res;
    }
};


int main()
{
    vector<vector<int>> res;
    vector<int> nums{0, 0, 0, 0};

    Solution1 s1;
    res = s1.threeSum(nums);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << ", ";
        }
        cout << endl;
    }
    return 0;
}
