#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    std::vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    int len = s.removeElement(nums, val);
    for (int i = 0; i < len; i++) {
        std::cout << nums[i] << ", ";
    }
    std::cout << std::endl;
}