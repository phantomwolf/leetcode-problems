#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;


int findMaxLength (vector<int> &nums)
{
    unordered_map<int, int> m;
    int max_length = 0;
    int count = 0;
    m.insert({0, -1});
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 0)
            --count;
        else
            ++count;
        unordered_map<int, int>::iterator iter;
        iter = m.find(count);
        if (iter == m.end()) {
            // same count not found
            m.insert({count, i});
            continue;
        }
        int length = i - iter->second;
        if (length > max_length)
            max_length = length;
    }
    return max_length;
}


int main()
{
    vector<int> nums{0, 1, 0, 1};
    int longest = findMaxLength(nums);
    cout << "longest subarray: " << longest << endl;

    return 0;
}
