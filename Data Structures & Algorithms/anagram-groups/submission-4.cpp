class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) {
            return {{}};
        }

        std::unordered_map<std::string, std::vector<std::string>> dict;

        for (const auto& str : strs) {
            std::string key(26, '0');
            for (auto c : str) {
                key[c - 'a']++;
            }
            dict[key].push_back(str);
        }

        std::vector<std::vector<std::string>> result;

        for (const auto& [_, value] : dict) {
            result.push_back(value);
        }

        return result;
    }
};
