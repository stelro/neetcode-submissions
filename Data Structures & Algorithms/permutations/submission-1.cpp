class Solution {

    std::vector<std::vector<int>> result;
	

	void dfs(const std::vector<int>& nums, std::vector<int>& subset, std::vector<bool>& visited) {
		if (subset.size() == nums.size()) {
			result.push_back(subset);
			return;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (!visited[i]) {
				subset.push_back(nums[i]);
				visited[i] = true;
				dfs(nums, subset, visited);
				visited[i] = false;
				subset.pop_back();
			}
		}
	}

public:
	std::vector<std::vector<int>> permute(const std::vector<int>& nums) {
		std::vector<int> subset;
		std::vector<bool> visited (nums.size(), false);
		dfs(nums, subset, visited);
		return result;
    }
};