class Solution {
 public:
  int maxArea(vector<int>& height) {
    int result = 0;
    int left = 0, right = height.size() - 1;
    while (left < right) {
      int area = (right - left) * min(height[left], height[right]);
      result = max(area, result);
      if (height[left] < height[right]) {
        // The only chance of a greater area is finding a greater height[left]
        left++;
      } else if (height[left] > height[right]) {
        right--;
      } else {
        left++;
        right--;
      }
    }
    return result;
  }
};