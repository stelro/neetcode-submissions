class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
		return 0;
        }

        std::set<char> seen;
        seen.insert(s[0]);
        
        int left = 0;
        int right = 1;

        int result = 1;

        while (right < s.size()) {
            if (seen.count(s[right]) == 0) {
                seen.insert(s[right]);
                right++;
            } else {
                seen.erase(s[left]);
                left++;
            }
            result = std::max(result, (int)seen.size());
        }

        return result;
    }
};
