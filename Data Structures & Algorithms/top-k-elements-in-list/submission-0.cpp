class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq_map; // key -> count
        for (const auto& n : nums) {
            freq_map[n]++;
        }

        std::vector<std::vector<int>> freq (nums.size() + 1);
        for (const auto& [k, v] : freq_map) {
            freq[v].push_back(k);
        }

        std::vector<int> result;
        for (int i = freq.size() - 1; i > 0; --i) {
            for (const auto& t : freq[i]) {
                if (result.size() == k) {
                    break;
                }
                result.push_back(t);
            }
        }
        return result;
    }
};
