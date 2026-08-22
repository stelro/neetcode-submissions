class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> set(nums.begin(), nums.end());
        int longest = 0;
        for (int i = 0; i < nums.size(); i++) {
            int longest_so_far = 1;
            while (set.count(nums[i] + longest_so_far)) {
                longest_so_far++;
            }
            longest = std::max(longest, longest_so_far);
        }

        return longest;
    }
};
