class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string result;

        int min_len = std::numeric_limits<int>::max();
        for (const auto& str : strs) {
            min_len = std::min(min_len, (int)str.size());
        }

        for (int i = 0; i < min_len; i++) {
            char ch = strs[0][i];
            for (const auto& str : strs) {
                if (ch != str[i]) return result;
            }
            result.push_back(ch);
        }

        return result;
    }
};