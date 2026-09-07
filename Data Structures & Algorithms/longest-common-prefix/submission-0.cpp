class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string result;

        int max_len = 0;
        for (const auto& str : strs) {
            max_len = std::max(max_len, (int)str.size());
        }

        for (int i = 0; i < max_len; i++) {
            char ch = strs[0][i];
            for (const auto& str : strs) {
                if (ch != str[i]) return result;
            }
            result.push_back(ch);
        }

        return result;
    }
};