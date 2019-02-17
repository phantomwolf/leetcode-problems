#include <iostream>
#include <vector>
using namespace std;

void shell_sort(vector<int> &nums)
{
    int length = nums.size();
    int h = 1;
    while (h < length / 3)
    {
        h = 3 * h + 1;
    }
    while (h >= 1)
    {
        for (int i = h; i < length; i++)
        {
            for (int j = i; j >= h && nums[j] < nums[j - h]; j -= h)
            {
                std::swap(nums[j], nums[j - h]);
            }
        }
        h /= 3;
    }
}

int main(int argc, char *argv[])
{
    vector<int> nums{3, 8, 2, 1, 7, 5, 4, 6};
    shell_sort(nums);
    for (auto i : nums)
    {
        cout << i << endl;
    }

    return 0;
}