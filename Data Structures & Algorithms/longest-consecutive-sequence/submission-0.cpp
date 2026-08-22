class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> seq(nums.begin(), nums.end());
        int longest = 0;

        for (auto n : nums) {
            if (!seq.count(n-1)) {
                int longest_so_far = 0;
                while (seq.count(n + longest_so_far)) {
                    longest_so_far++;
                }
                longest = std::max(longest, longest_so_far);
            }
            
        }

        return longest;
    }
};
