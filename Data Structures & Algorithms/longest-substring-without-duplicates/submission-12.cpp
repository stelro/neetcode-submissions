class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;

        std::unordered_set<char> set;

        int longest = 1;
        int left = 0;
        int right = 1;
        set.insert(s[left]);
        while (right < s.size()) {
            while (set.contains(s[right])) {
                set.erase(s[left++]);
            }
            set.insert(s[right]);
            longest = std::max(longest, (int)set.size());
            right++;
        }

        return longest;
    }
};
