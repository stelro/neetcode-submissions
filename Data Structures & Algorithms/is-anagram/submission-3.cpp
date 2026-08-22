class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
       std::vector<int> freq(26, 0);
       for (std::size_t i = 0; i < s.size(); ++i) {
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
       }

       for (auto f : freq) {
        if (f != 0) return false;
       }
       return true;
    }
};
