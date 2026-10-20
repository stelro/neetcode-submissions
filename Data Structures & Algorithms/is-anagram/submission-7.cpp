class Solution {
   public:
    bool isAnagram(string s, string t) {
        std::unordered_multiset<char> set1(s.begin(), s.end());
        std::unordered_multiset<char> set2(t.begin(), t.end());

        return set1 == set2;
    }
};
