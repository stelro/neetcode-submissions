class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int n = matrix.size() * matrix[0].size();
        int cols = matrix[0].size();

        int left = 0;
        int right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int row = mid / cols;
            int col = mid % cols;
            if (target == matrix[row][col]) {
                return true;
            } else if (matrix[row][col] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // for (int i = 0; i < n; i++) {
        // 	int row = i % cols;
        // 	int col = i / cols;
        // 	//std::println("i : {} - row: {} | col: {} ", i, row, col);
        // 	std::println("{} ", matrix[row][col]);
        // }
            
        return false;
    }
};
