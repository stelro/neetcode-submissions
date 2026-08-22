class Solution {
public:

    string encode(vector<string>& strs) {
        std::string result;
        for (const auto& s : strs) {
            std::size_t len = s.size();
            result += '#';
            result += std::to_string(len);
            result += '#';
            result += s;
            result += '#';
        }
        return result;
    }

    vector<string> decode(string str) {
        if (str.empty() || str[0] != '#') return {};
        std::vector<std::string> result;

        for (int i = 0; i < str.size(); i++) {
            int len = 0;
            if (str[i] == '#' && std::isdigit(str[i + 1])) {
                i++; // Eat the '#'
                std::string len_str;
                while (std::isdigit(str[i])) {
                    len_str += str[i];
                    i++;
                }
                len = std::stoi(len_str);
                i++; // eat the closing '#'
            }
            result.push_back(str.substr(i, len));
            i += len;
        }
        return result;
    }
};
