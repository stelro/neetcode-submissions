class Solution {
public:
    int trap(vector<int>& height) {
       if (height.empty()) {
            return 0;
       }

       int n = height.size();
       std::vector<int> leftMax(n);
       std::vector<int> rightMax(n);

       leftMax[0] = height[0];
       rightMax[n-1] = height[n-1];

       for (int i = 0; i < n; i++) {
        leftMax[i] = std::max(leftMax[i - 1], height[i]);
       }

       for (int i = n - 1; i > 0; i--) {
        rightMax[i - 1] = std::max(rightMax[i], height[i - 1]);
       }

       int result = 0;
       for (int i = 0; i < n; i++) {
            result += std::min(leftMax[i], rightMax[i]) - height[i];
       }
       
       return result;
    }
};
