class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    
    for (auto n : nums) {
		int idx = std::abs(n) - 1;
		if (nums[idx] < 0) {
			return std::abs(n);
		}
		nums[idx] *= -1;
	}
	return 0;
    }
};
