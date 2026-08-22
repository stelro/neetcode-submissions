class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (auto& n : nums) {
            int index = std::abs(n) - 1;
            if (nums[index] < 0) {
                return std::abs(n);
            }
            nums[index] *= - 1;
        }
    }
};
