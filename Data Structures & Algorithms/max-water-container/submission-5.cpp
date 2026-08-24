class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int result = 0;

        int left = 0;
        int right = heights.size() - 1;

        while (left < right) {
            int area = std::min(heights[left], heights[right]) * (right - left);
            ;
            if (heights[left] > heights[right]) {
                right--;
            } else {
                left++;
            }
            result = std::max(result, area);
        }

        return result;
    }
};
