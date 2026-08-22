class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::unordered_map<char, int> need_m;
        for (auto c : s1) {
            need_m[c]++;
        }

        std::unordered_map<char, int> have_m;
        int need = need_m.size();
        int have = 0;

        int left = 0;
        for (int right = 0; right < s2.size(); right++) {
            char c = s2[right];
            have_m[c]++;
            if (need_m.count(c) && have_m[c] == need_m[c]) {
                have++;
            }

            if ((right - left + 1) > s1.size()) {
                char lc = s2[left];
                if (need_m.count(lc) && have_m[lc] == need_m[lc]) {
                    have--;
                }
                have_m[lc]--;
                left++;
            }
            if (have == need) {
                return true;
            }
        }
        return false;
    }
};
