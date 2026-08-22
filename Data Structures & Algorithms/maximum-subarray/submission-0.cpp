class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = std::numeric_limits<int>::min();
        int max_so_far = 0;
        for (auto n : nums) {
            if (max_so_far < 0) {
                max_so_far = n;
            } else {
                max_so_far += n;
            }
            result = std::max(result, max_so_far);
        }

        return result;
    }
};
