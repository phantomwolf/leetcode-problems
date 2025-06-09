#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int i = 0, j = n-1;
        for (int k = n-1; k >= 0; k--) {
            if (abs(nums[i]) < abs(nums[j])) {
                res[k] = nums[j] * nums[j];
                j--;
            } else {
                res[k] = nums[i] * nums[i];
                i++;
            }
        }
        return res;
    }
};