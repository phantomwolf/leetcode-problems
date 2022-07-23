package TrappingRainWater;

public class Solution1 {
    public int trap(int[] height) {
        int[] leftMax = new int[height.length];
        int[] rightMax = new int[height.length];
        int max = 0;
        for (int i = 0; i < height.length; i++) {
            if (max < height[i]) {
                max = height[i];
            }
            leftMax[i] = max;
        }
        max = 0;
        for (int i = height.length - 1; i >= 0; i--) {
            if (max < height[i]) {
                max = height[i];
            }
            rightMax[i] = max;
        }

        int res = 0;
        for (int i = 1; i < height.length - 1; i++) {
            int diff = Math.min(leftMax[i], rightMax[i]) - height[i];
            if (diff > 0) {
                res += diff;
            }
        }
        return res;
    }
}
