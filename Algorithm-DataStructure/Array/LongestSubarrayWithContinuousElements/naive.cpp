#include <iostream>
#include <vector>

using namespace std;


int longest_subarray_continuous (const vector<int> &nums, vector<int> &subarr)
{
    // subarray start position
    int size = nums.size();
    int longest = 1;
    int m = 0, n = 0;
    for (int i = 0; i < size - 1; ++i) {
        int min = nums[i], max = nums[i];
        for (int j = i + 1; j < size; ++j) {
            if (nums[j] < min)
                min = nums[j];
            if (nums[j] > max)
                max = nums[j];
            if (max - min == j - i && longest < j - i + 1) {
                longest = j - i + 1;
                m = i;
                n = j;
            }
        }
    }
    cout << "m: " << m << ", n: " << n << endl;
    for (size_t i = m; i <= n; ++i) {
        subarr.push_back(nums[i]);
    }
    return longest;
}


int main()
{
    vector<int> nums{1, 56, 58, 57, 90, 92, 94, 93, 91, 45};
    vector<int> subarr;

    size_t longest = longest_subarray_continuous (nums, subarr);
    cout << "longest subarray: " << longest << endl;
    cout << "[";
    for (size_t i = 0; i < subarr.size(); ++i) {
        cout << subarr[i] << ", ";
    }
    cout << "]" << endl;

    return 0;
}
