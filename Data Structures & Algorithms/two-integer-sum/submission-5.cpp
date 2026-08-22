class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> index_map; // n / index
        for (int i = 0; i < nums.size(); i++) {
            index_map[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (index_map.contains(diff) && index_map[diff] != i) {
                return {i, index_map[diff]};
            }
        }

        return {};
    }
};
