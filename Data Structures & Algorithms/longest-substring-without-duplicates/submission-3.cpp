class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
		return 0;
        }

        std::unordered_set<char> seen;
        seen.insert(s[0]);
        
        int left = 0;
        int right = 1;
        int result = 1;

        while (right < s.size()) {
            while (seen.find(s[right]) != seen.end()) {
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            right++;
            result = std::max(result, (int)seen.size());
        }

        return result;
    }
};
