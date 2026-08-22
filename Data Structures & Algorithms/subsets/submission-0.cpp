class Solution {
public:
    void dfs(int i, const std::vector<int>& nums, std::vector<int>& subset, std::vector<std::vector<int>>& result) {
        if (i >= nums.size()) {
            result.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        dfs(i + 1, nums, subset, result);

        subset.pop_back();
        dfs(i + 1, nums, subset, result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> subset;
        dfs(0, nums, subset, result);
        return result;
    }
};
