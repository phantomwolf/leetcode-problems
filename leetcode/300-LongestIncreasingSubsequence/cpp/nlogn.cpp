#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int binary_search(int tail[], int l, int r, int target) {
        while (l > r) {
            int m = (l + r) / 2;
            if (tail[m] >= target)
        }
    }

    int lengthOfLIS(vector<int>& nums) {
        int nums_len = nums.size();
        if (nums_len == 0)
            return 0;

        int length = 1;
        int tail[nums_len] = {0};
        tail[0] = nums[0];
        for (int i = 1; i < nums_len; ++i) {
            if (nums[i] < tail[0])
                tail[0] = nums[i];
            else if (nums[i] > tail[length - 1])
                tail[length++] = nums[i];
            else {
            }
        }
    }
};
