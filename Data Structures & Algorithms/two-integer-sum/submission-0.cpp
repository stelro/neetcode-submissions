class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> freq; // value -> inedex
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]] = i;
        }   

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (freq.count(diff) && freq[diff] != i) {
                return {i, freq[diff]};
            }
        }
    }
};
