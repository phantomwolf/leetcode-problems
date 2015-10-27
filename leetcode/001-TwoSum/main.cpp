#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (umap.count(complement)) {
                return vector<int>({umap.find(complement)->second, i});
            }
            umap.insert({nums[i], i});
        }
        return vector<int>();
    }
};

int main()
{
    Solution s;
    vector<int> nums {3, 2, 4};
    vector<int> res = s.twoSum(nums, 6);
    cout << "[ " << res[0] << ", " << res[1] << " ]" << endl;

    return 0;
}
