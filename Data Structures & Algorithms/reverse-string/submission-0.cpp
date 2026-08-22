class Solution {
   public:
    void reverseString(vector<char>& s) {
        if (s.empty()) return;

        int first = 0;
        int last = s.size() - 1;

        while (first < last) {
            std::swap(s[first], s[last]);
            first++;
            last--;
        }
    }
};