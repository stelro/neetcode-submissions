class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        
        std::multiset<char> freq_1;
        std::multiset<char> freq_2;

        for (size_t i = 0; i < s.size(); i++) {
            freq_1.insert(s[i]);
            freq_2.insert(t[i]);
        }

        return freq_1 == freq_2;

    }
};
