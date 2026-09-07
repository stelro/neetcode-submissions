class Solution {
   public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = height[0], rightMax = height[right];
        int result = 0;

        while (left <= right) {
            if (leftMax < rightMax) {
                leftMax = std::max(leftMax, height[left]);
                int x = leftMax - height[left];
                left++;
                result += x;
            } else {
                rightMax = std::max(rightMax, height[right]);
                int x = rightMax - height[right];
                right--;
                result += x;
            }
        }

        return result;
    }
};
