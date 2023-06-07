#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int j = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};
