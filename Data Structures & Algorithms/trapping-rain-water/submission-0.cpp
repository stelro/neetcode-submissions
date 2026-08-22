class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        int total = 0;
        int maxLeft = height[0];
        int maxRight = height[height.size() - 1];

        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            if (height[left] < height[right]) {
                left++;
                maxLeft = std::max(maxLeft, height[left]);
                total += maxLeft - height[left];
            } else {
                right--;
                maxRight = std::max(maxRight, height[right]);
                total += maxRight - height[right];
            }
        }

        return total;
    }
};
