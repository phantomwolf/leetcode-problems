#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

// Merge procedure
class Solution1
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        const int total = nums1.size() + nums2.size();
        int i = 0, j = 0;
        int k = (total % 2 == 0) ? total/2 : total/2 + 1;
        while (i != nums1.size() && j != nums2.size() && k != 1) {
            if (nums1[i] <= nums2[j])
                ++i;
            else
                ++j;
            --k;
        }
        if (i == nums1.size()) {
            if (total % 2 != 0)
                return nums2[j + k - 1];
            return (nums2[j + k - 1] + nums2[j + k]) / 2.0;
        }
        if (j == nums2.size()) {
            if (total % 2 != 0)
                return nums1[i + k - 1];
            return (nums1[i + k - 1] + nums1[i + k]) / 2.0;
        }
        // k == 1
        int a, b;
        if (nums1[i] <= nums2[j]) {
            a = nums1[i];
            ++i;
        } else {
            a = nums2[j];
            ++j;
        }
        if (total % 2 != 0)
            return a;
        if (i == nums1.size())
            b = nums2[j];
        else if (j == nums2.size())
            b = nums1[i];
        else
            b = min(nums1[i], nums2[j]);
        return (a + b) / 2.0;
    }
};

// Binary search
class Solution2 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        int half = total / 2;

        if (nums1.size() > nums2.size()) {
            std::swap(nums1, nums2);
        }

        int lo1 = 0, hi1 = nums1.size() - 1;
        while (true) {
            // Why not mi1 = (lo1 + hi1) / 2? Because if lo1 + hi1 is negative, std::floor will return 0 instead of -1
            int mi1 = (int) std::floor((lo1 + hi1) / 2.0);
            // [0, 1, ..., mi1 | mi1+1, ..., total-1] and [0, 1, ..., mi2 | mi2+1, ..., total-1]
            // mi1 + 1 + mi2 + 1 == half
            int mi2 = half - mi1 - 2;
            int left1 = (mi1 >= 0) ? nums1[mi1] : INT_MIN;
            int right1 = (mi1 + 1 < nums1.size()) ? nums1[mi1 + 1] : INT_MAX;
            int left2 = (mi2 >= 0) ? nums2[mi2] : INT_MIN;
            int right2 = (mi2 + 1 < nums2.size()) ? nums2[mi2 + 1] : INT_MAX;
            if (left1 <= right2 && left2 <= right1) {
                if (total % 2 == 0) {
                    return static_cast<double>(std::max(left1, left2) + std::min(right1, right2)) / 2;
                } else {
                    return std::min(right1, right2);
                }
            } else if (left1 > right2) {
                hi1 = mi1 - 1;
            } else {
                lo1 = mi1 + 1;
            }
        }
    }
};

int main()
{
    srand(time(NULL));

    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {1, 2};
    print_nums("nums1", nums1);
    print_nums("nums2", nums2);
    merge_show(nums1, nums2);

    double median1, median2;
    Solution1 s1;
    median1 = s1.findMedianSortedArrays(nums1, nums2);
    cout << "median1: " << median1 << endl;
    Solution2 s2;
    median2 = s2.findMedianSortedArrays(nums1, nums2);
    cout << "median2: " << median2 << endl;
    return 0;
}
