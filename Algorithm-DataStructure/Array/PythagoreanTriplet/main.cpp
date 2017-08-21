#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class AbsCmp
{
public:
    bool operator() (int a, int b) const
    {
        if (a < 0)
            a = -a;
        if (b < 0)
            b = -b;
        return a < b;
    }
};


bool pythagorean_triplet (vector<int> &nums, vector<int> &triplet)
{
    // Sort the array in ascendant order by absolute value
    sort(nums.begin(), nums.end(), AbsCmp());

    for (size_t c = nums.size() - 1; c >= 2; --c) {
        size_t a = 0, b = c - 1;
        while (a < b) {
            int tmp = nums[a] * nums[a] - nums[c] * nums[c] + nums[b] * nums[b];
            if (tmp == 0) {
                triplet = {nums[a], nums[b], nums[c]};
                return true;
            } else if (tmp < 0)
                ++a;
            else
                --b;
        }
    }
    return false;
}


int main (int argc, char *argv[])
{
    vector<int> nums{3, 1, 4, 6, 5};
    vector<int> triplet;
    bool res = pythagorean_triplet(nums, triplet);
    if (!res) {
        cout << "No pythagorean triplet found" << endl;
        return 0;
    }
    cout << "Pythagorean triplet: ";
    for (int i = 0; i < 3; ++i) {
        cout << triplet[i] << ", ";
    }
    cout << endl;

    return 0;
}
