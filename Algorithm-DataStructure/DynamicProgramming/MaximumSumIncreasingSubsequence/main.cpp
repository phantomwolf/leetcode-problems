#include <iostream>
#include <vector>

using namespace std;


int max_sum_increasing_subsequence(vector<int> &nums)
{
    int len = nums.size();
    int d[len];

    for (int i = 0; i < len; ++i) {
        d[i] = nums[i];
    }

    for (int i = 1; i < len; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j] && d[i] < d[j] + nums[i])
                d[i] = d[j] + nums[i];
        }
    }

    int max = d[0];
    for (int i = 1; i < len; ++i) {
        if (d[i] > max)
            max = d[i];
    }
    return max;
}

int main()
{
    vector<int> nums{1, 101, 2, 3, 100, 4, 5};

    int res = max_sum_increasing_subsequence(nums);
    cout << "result: " << res << endl;
    return 0;
}
