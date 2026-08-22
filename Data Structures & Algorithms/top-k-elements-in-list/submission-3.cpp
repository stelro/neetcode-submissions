class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        for (auto n : nums) {
            freq[n]++;
        }

        std::vector<std::vector<int>> tmp(nums.size() + 1);
        for (const auto& [key, value] : freq) {
            tmp[value].push_back(key);
        }

        std::vector<int> result;
        for (int i = tmp.size() - 1; i >= 0; i--) {
            if (tmp[i].empty()) {
                continue;
            }
            for (auto j : tmp[i]) {
                if (result.size() < k) {
                    result.push_back(j);
                }
            }
        }

        return result;
    }
};
