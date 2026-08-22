class Solution {
public:
    bool binary_search(const std::vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return true;
            }

            if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size();

        // upper bound
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (matrix[mid].empty()) 
                break;
            if (matrix[mid][0] == target) {
                return true;
            }
            if (matrix[mid][0] <= target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        if (low == 0) {
            return false;
        }

        return binary_search(matrix[low - 1], target);
        return false;
    }
};
