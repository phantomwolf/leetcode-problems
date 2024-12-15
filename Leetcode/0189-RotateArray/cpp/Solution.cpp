#include <cassert>
#include <utility>
#include <vector>

using std::vector;

class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            std::swap(nums[start++], nums[end--]);
        }
    }

    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 10;

    Solution s;
    s.rotate(nums, k);
    // Verify
    vector<int> expected = {5,6,7,1,2,3,4};
    for (int i = 0; i < nums.size(); i++) {
        assert(nums[i] == expected[i]);
    }
}

