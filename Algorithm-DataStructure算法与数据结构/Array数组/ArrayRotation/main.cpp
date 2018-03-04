#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

using namespace std;

class SwapSolution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if (k == 0)
            return;
        vector<int>::iterator l = nums.begin();
        vector<int>::iterator r = nums.end();
        vector<int>::iterator d = nums.end() - k;
        int len1 = d - l;
        int len2 = r - d;
        while (len1 != len2) {
            if (len1 < len2) {
                swap_ranges(l, d, r - len1);
                d = l + len1;
                r -= len1;
            } else {
                swap_ranges(d, r, l);
                l += len2;
            }
            len1 = d - l;
            len2 = r - d;
        }
        swap_ranges(d, r, l);
    }
};

class ReverseSolution {
public:
    void reverse(vector<int> &nums, int l, int r) {
        while (l < r) {
            int tmp;
            tmp = nums[l];
            nums[l] = nums[r];
            nums[r] = tmp;
            ++l;
            --r;
        }
    }

    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if (k == 0)
            return;
        int d = nums.size() - k;
        this->reverse(nums, 0, d-1);
        this->reverse(nums, d, nums.size()-1);
        this->reverse(nums, 0, nums.size()-1);
    }
};

unsigned int gcd(unsigned int n1, unsigned int n2)
{
    return (n2 == 0) ? n1 : gcd(n2, n1 % n2);
}

// Jungling algorithm
void jungling_rotate(int a[], int n, int d)
{
    int tmp;
    const int divisor = gcd(n, d);
    for (int i=0; i < divisor; ++i) {
        tmp = a[i];
        int j = i;
        while (true) {
            int k = j + d;
            if (k >= n)
                k -= n;
            if (k == i)
                break;
            a[j] = a[k];
            j = k;
        }
        a[j] = tmp;
    }
}

void swap_block(int a[], int l1, int len1, int l2)
{
    while (len1 != 0) {
        int tmp;
        tmp = a[l1];
        a[l1] = a[l2];
        a[l2] = tmp;
        ++l1;
        ++l2;
        --len1;
    }
}

void swap_rotate(int a[], int l, int r, int d)
{
    int len1 = d - l, len2 = r - d + 1;
    if (len1 == 0 || len2 == 0)
        return;
    if (len1 < len2) {
        int pivot = r - len1 + 1;
        swap_block(a, l, len1, pivot);
        swap_rotate(a, l, r - len1, l + len1);
    } else if (len1 > len2) {
        swap_rotate(a, l + len2, r, r - len2 + 1);
        swap_block(a, l, len2, d);
    } else {
        swap_block(a, l, len1, d);
    }
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    //SwapSolution s;
    ReverseSolution s;
    s.rotate(nums, 3);

    for (int i=0; i < nums.size(); ++i) {
        cout << nums[i] << ", ";
    }
    cout << endl;
    return 0;
}
