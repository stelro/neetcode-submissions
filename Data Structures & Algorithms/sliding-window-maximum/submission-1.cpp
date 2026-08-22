class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            int max_so_far = nums[i];
            for (int j = 0; j < k; j++) {
                if (i + j >= nums.size()) return result;
                max_so_far = std::max(max_so_far, nums[j + i]);
            }
            result.push_back(max_so_far);
        }

        return result;
    }
};
