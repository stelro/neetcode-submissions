class Solution {
public:
void dfs(int i, std::vector<std::vector<int>>& result, std::vector<int>& subset, const std::vector<int>& nums) {
	if (i >= nums.size()) {
		result.push_back(subset);
		return;
	}

	subset.push_back(nums[i]);
	dfs(i + 1, result, subset, nums);

	subset.pop_back();
	dfs(i + 1, result, subset, nums);

}

std::vector<std::vector<int>> subsets(const std::vector<int>& nums) {
	std::vector<std::vector<int>> result;
	std::vector<int> subset;
	dfs(0, result, subset, nums);
	return result;
}
};
