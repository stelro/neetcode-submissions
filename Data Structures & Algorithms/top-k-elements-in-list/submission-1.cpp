class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        std::unordered_map<int, int> freq; // index, freq
        for (auto n : nums) {
            freq[n]++;
        }

        std::vector<std::vector<int>> buckets (nums.size() + 1);

        for (const auto& [k, v] : freq) {
            buckets[v].push_back(k);
        }

        std::vector<int> result;
        for (int i = buckets.size() - 1; i >= 0; --i) {
            if (buckets[i].empty()) { continue; }
            for (const auto& v : buckets[i]) {
                if (result.size() == k) {
                    break;
                }
                result.push_back(v);
            }
        }

        return result;;

    }
};
