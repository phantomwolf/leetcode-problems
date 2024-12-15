#include <cassert>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Boyer–Moore majority vote algorithm
        // First iteration
        int result = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                result = nums[i];
                count = 1;
            } else if (nums[i] == result) {
                count++;
            } else {
                count--;
            }
        }
        // Second iteration: since the majority element is guaranteed to exist, there's no need for 2nd iteration of verification
        return result;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {2,2,1,1,1,2,2};
    
    Solution s;
    int result = s.majorityElement(nums);
    cout << "majority element: " << result << endl;
    assert(result == 2);
}
