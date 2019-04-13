#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int max_area = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            int h = (height[l] < height[r]) ? height[l] : height[r];
            int area = (r - l) * h;
            if (area > max_area)
                max_area = area;
            if (height[l] < height[r])
                ++l;
            else
                --r;
        }
        return max_area;
    }
};

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution s;
    cout << s.maxArea(height) << endl;
    return 0;
}
