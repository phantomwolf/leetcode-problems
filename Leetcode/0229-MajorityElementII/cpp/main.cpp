#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        vector<int> res;
        // 出现次数多于⌊ n/3 ⌋的元素不会多于2个
        int cand1, cand2;
        int count1 = 0, count2 = 0;
        for (auto i : nums) {
            if (i == cand1) {
                count1++;
            } else if (i == cand2) {
                count2++;
            } else if (count1 == 0) {
                cand1 = i;
                count1++;
            } else if (count2 == 0) {
                cand2 = i;
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        for (auto i : nums) {
            if (i == cand1)
                count1++;
            else if (i == cand2)
                count2++;
        }
        if (count1 > nums.size() / 3)
            res.push_back(cand1);
        if (count2 > nums.size() / 3)
            res.push_back(cand2);
        return res;
    }
};


int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {1, 1, 1, 2, 2, 2, 3, 4};
    vector<int> res = s.majorityElement(nums);
    cout << "Result: ";
    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
