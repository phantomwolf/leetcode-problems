#include <cassert>
#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    int removeDuplicates(vector<int>& nums);
};

int Solution::removeDuplicates(vector<int>& nums) {
    // Special case
    if (nums.size() < 3) {
        return nums.size();
    }
    int k = 2;
    for (int i = 2; i < nums.size(); i++) {
        if (nums[k-2] != nums[i]) {
            nums[k++] = nums[i];
        }
    }
    return k;
}


int main(int argc, char *argv[]) {
    vector<int> nums = {0,0,1,1,1,1,2,3,3};

    Solution s;
    int k = s.removeDuplicates(nums);
    cout << "k: " << k << endl;
    assert(k == 7);
}
