class Solution {
public:
    bool isAnagram(string s, string t) {
      if (s == t) return true;
      if (s.size() != t.size()) return false;

      std::vector<int> s_s(26,0);

      for (int i = 0; i < s.size(); i++) {
        s_s[s[i] - 'a']++;
        s_s[t[i] - 'a']--;
      }

    for (auto n : s_s) {
        if (n != 0) return false;
    }
    return true;
    }
};
