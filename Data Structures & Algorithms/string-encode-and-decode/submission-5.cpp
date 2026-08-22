class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) {
            return {};
        }
        
        std::string result;
        for (const auto& str : strs) {
            result += "#" + std::to_string(str.size()) + "#";
            result += str;
        }

        return result;
    }

    vector<string> decode(string str) {
        if (str.empty()) {
            return {};
        }
        if (str[0] != '#') {
            return {};
        }

        std::vector<std::string> result;
        for (int i = 1; i < str.size(); ++i) {
            if (str[i - 1] == '#') {
                std::string len_str;
                while (std::isdigit(str[i]) && str[i] != '#') {
                    len_str += str[i++];
                }
                i++; // consume '#'
                int length = std::stoi(len_str);
                std::string tmp;
                for (int j = 0; j < length; j++) {
                    tmp += str[i + j];
                }
                i += length;
                result.push_back(tmp);
            }
        }

        return result;
    }
};
