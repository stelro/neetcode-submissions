class Solution {
public:
    int findMin(vector<int> &nums) {
        int min = nums[0];
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            if (nums[left] < nums[right]) {
                min = std::min(min, nums[left]);
                break;
            }

            int mid = left + (right - left) / 2;
            min = std::min(min, nums[mid]);

            if (nums[mid] >= nums[left]) {
                // If the mid is greater than the left,
                // that means that the left order is perfectly sorted
                // so the element we are looking for is in the right
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return min;
    }
};
