class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> seq(nums.begin(), nums.end());

        int longest = 0;

        for (int i = 0; i < (int)nums.size(); i++) {
            int longest_so_far = 1;
            int num = nums[i];
            if (seq.contains(num - 1)) continue;
            while (seq.contains(++num)) {
                longest_so_far++;
            }

            longest = std::max(longest, longest_so_far);
        }

        return longest;
    }
};
