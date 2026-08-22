class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty()) return {};
	
        size_t n = nums.size();
        std::vector<int> prefix (nums.size());
        std::vector<int> suffix (nums.size());
        prefix[0] = 1;
        suffix[n - 1] = 1;

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; i++) {
            nums[i] = suffix[i] * prefix[i];
        }

        return nums;
    }
};
