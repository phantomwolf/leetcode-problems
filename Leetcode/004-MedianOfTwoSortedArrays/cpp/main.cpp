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

// kth
// 设两个数组的长度分别为m和n。问题转化为求两个数组的第(m+n)/2
class Solution2
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        const int total = nums1.size() + nums2.size();
        int len1 = nums1.size(), len2 = nums2.size();
        int k = (total % 2 == 0) ? total/2 : total/2 + 1;
        int l1 = 0, l2 = 0; // 边界
        int a, b;
        while (k != 1 && len1 != 0 && len2 != 0) {
            int p1, p2; // 要比较的元素的下标
            if (len1 <= len2) {
                p1 = min(l1 + k/2, l1 + len1);
                p2 = k + l1 + l2 - p1;
            } else {
                p2 = min(l2 + k/2, l2 + len2);
                p1 = k + l1 + l2 - p2;
            }
            if (nums1[p1 - 1] < nums2[p2 - 1]) {
                k -= p1 - l1;
                l1 = p1;
                len1 = nums1.size() - l1;
            } else if (nums1[p1 - 1] > nums2[p2 - 1]) {
                k -= p2 - l2;
                l2 = p2;
                len2 = nums2.size() - l2;
            } else {
                a = nums1[p1 - 1];
                if (total % 2 != 0)
                    return a;
                ++p1;
                ++p2;
                if (p1 - 1 == nums1.size())
                    b = nums2[p2 - 1];
                else if (p2 - 1 == nums2.size())
                    b = nums1[p1 - 1];
                else
                    b = min(nums1[p1 - 1], nums2[p2 - 1]);
                return (a + b) / 2.0;
            }
        }
        if (len1 == 0) {
            if (total % 2 != 0)
                return nums2[l2 - 1 + k];
            return (nums2[l2 - 1 + k] + nums2[l2 + k]) / 2.0;
        }
        if (len2 == 0) {
            if (total % 2 != 0)
                return nums1[l1 - 1 + k];
            return (nums1[l1 - 1 + k] + nums1[l1 + k]) / 2.0;
        }
        // k == 1
        if (nums1[l1] < nums2[l2]) {
            a = nums1[l1];
            ++l1;
        } else {
            a = nums2[l2];
            ++l2;
        }
        if (total % 2 != 0)
            return a;
        if (l1 == nums1.size())
            b = nums2[l2];
        else if (l2 == nums2.size())
            b = nums1[l1];
        else
            b = min(nums1[l1], nums2[l2]);
        return (a + b) / 2.0;
    }
};

void prepare(vector<int> &nums, vector<int>::size_type nums_size)
{
    for (int i = 0; i < nums_size; ++i) {
        nums.push_back(rand() % 100);
    }
    sort(nums.begin(), nums.end());
}

void print_nums(string name, const vector<int> &nums)
{
    vector<int>::const_iterator iter = nums.begin();
    cout << name << ": ";
    while (iter != nums.end()) {
        cout << *iter << ", ";
        ++iter;
    }
    cout << endl;
}

void merge_show(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> res;
    vector<int>::iterator iter = nums1.begin();
    while (iter != nums1.end()) {
        res.push_back(*iter);
        ++iter;
    }
    iter = nums2.begin();
    while (iter != nums2.end()) {
        res.push_back(*iter);
        ++iter;
    }
    sort(res.begin(), res.end());
    iter = res.begin();
    cout << "merged: ";
    while (iter != res.end()) {
        cout << *iter << ", ";
        ++iter;
    }
    cout << endl;
}

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
