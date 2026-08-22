class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> freq; // value , index
        for (int i = 0; i < nums.size(); ++i) {
            freq[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (freq.count(diff) && i != freq[diff]) {
                return {i, freq[diff]};
            }
        }
        return {0,0};
    }
};
