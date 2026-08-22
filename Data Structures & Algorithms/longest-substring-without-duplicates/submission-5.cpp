class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       	if (s.empty()) return 0;

        std::unordered_set<char> set;
        int longest_substring = 0;
        
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            while (set.count(c)) {
                set.erase(s[left]);
                left++;
            }

            set.insert(c);
            longest_substring = std::max(longest_substring, (int)set.size());
        }

        return longest_substring;
    }
};
