class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty()) {
            return "";
        }

        std::unordered_map<char, int> t_map;
        for (auto c : t) {
            t_map[c]++;
        }

        int need = t_map.size();
        int have = 0;

        int min_substr = std::numeric_limits<int>::max();
        int min_substr_index = -1;

        int l = 0;
        std::unordered_map<char, int> s_map;

        for (int r = 0; r < s.size(); ++r) {
            char c = s[r];
            s_map[c]++;
            
            // if both maps have the same character and the same count
            // Incremenent the have counter
            if (t_map.count(c) && t_map[c] == s_map[c]) {
                have++;
            }

            // now try to shrink the window, to find the minimum
            while (have == need) {
                if ((r - l + 1) < min_substr) {
                    min_substr = (r - l + 1);
                    min_substr_index = l;
                }
                char d = s[l];
                s_map[d]--;

                if (t_map.count(d) && s_map[d] < t_map[d]) {
                    have--;
                }

                l++;
            }
        }

        return min_substr_index == -1 ? "" : s.substr(min_substr_index, min_substr);
    }
};
