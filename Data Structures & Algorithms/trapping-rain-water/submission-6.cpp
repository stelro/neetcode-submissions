class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
		    return 0;
        }
        
        std::size_t n = height.size();
        int result = 0;

        std::vector<int> left_max(n);
        std::vector<int> right_max(n);

        left_max[0] = height[0];
	for (std::size_t i = 1; i < n; ++i) {
		left_max[i] = std::max(left_max[i - 1], height[i]);
	}

	right_max[n - 1] = height[n - 1];
	for (int i = n - 2; i >= 0; --i) {
		right_max[i] = std::max(right_max[i + 1], height[i]);
	}

	for (std::size_t i = 0; i < n; i++) {
		result += std::min(left_max[i], right_max[i]) - height[i];
	}

        return result;
    }
};
