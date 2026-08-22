class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> map;
        for (auto s : strs) {
            std::string key (26, '0');
            for (int i = 0; i < s.size(); i++) {
                key[s[i] - 'a']++;
            }
            map[key].push_back(s);
        }

        std::vector<std::vector<std::string>> result;

        for (const auto& [_, value] : map) {
            std::vector<std::string> tmp;
            for (auto v : value) {
                tmp.push_back(v);
            }
            result.push_back(tmp);
        }
        return result;
    }
};
