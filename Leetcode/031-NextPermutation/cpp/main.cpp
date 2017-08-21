#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;


class Solution
{
public:
    void reverse(vector<int> &nums, int left, int right)
    {
        while (left < right) {
            swap(nums[left++], nums[right--]);
        }
    }

    void nextPermutation(vector<int> &nums)
    {
        if (nums.size() < 2)
            return;
        // Find the rightmost element which has
        // larger elements on its right
        int rightmost = nums.size() - 2;
        while (rightmost >= 0 && nums[rightmost] >= nums[rightmost + 1]) {
            rightmost--;
        }
        if (rightmost < 0) {
            // Input is in ascending order. Reverse it
            this->reverse(nums, 0, nums.size() - 1);
            return;
        }
        // Find the smallest element of those 
        // which are larger than rightmost element
        int smallest = rightmost + 1;
        while (smallest < nums.size() && nums[smallest] > nums[rightmost]) {
            smallest++;
        }
        swap(nums[rightmost], nums[smallest - 1]);
        // Reverse the elements after rightmost element
        // (because they're in descending order)
        this->reverse(nums, rightmost + 1, nums.size() - 1);
    }
};
