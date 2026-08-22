class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                // left side is sorted
                left = mid + 1;
            } else {
                // right side is sorted
                right = mid;
            }
        }

        return nums[left];
    }
};
