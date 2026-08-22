class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int max_area = 0;

        while (left < right) {

            int min = std::min(heights[left], heights[right]);
            int result = min * (right - left);
            max_area = std::max(max_area, result);

            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }


        return max_area;
    }
};
