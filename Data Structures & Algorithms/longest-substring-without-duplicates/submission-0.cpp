class Solution {
public:
    int lengthOfLongestSubstring(string s) {
          if (s.size() == 1) {
        return 1;
    }

    int left = 0;
    int right = 1;
    
    int max = 0;
    while (right < s.size()) {

        int first_unique = right;

        std::unordered_set<char> unique;
        unique.insert(s[left]);

        while (unique.count(s[right]) == 0 && right < s.size()) {
            unique.insert(s[right]);
            right++;
        }

        max = std::max(max, (int)unique.size());
        left = first_unique;
        right = first_unique;
        right++;
    }
   
    return max; 
    }
};
