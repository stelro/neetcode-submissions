class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq_map;
        for (auto n : nums) {
            freq_map[n]++;
        }

        std::vector<std::vector<int>> buckets(nums.size() + 1);
        for (auto& [key, value] : freq_map) {
            buckets[value].push_back(key);
        }

        std::vector<int> result;

        for (int i = buckets.size() - 1; i >= 0; --i) {
            if (buckets[i].empty()) continue;
            for (auto n : buckets[i]) {
                if (result.size() >= k) break;
                result.push_back(n);
            }
        }

        return result;
    }
};
