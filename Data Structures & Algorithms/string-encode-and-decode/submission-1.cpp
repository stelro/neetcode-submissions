class Solution {
public:

    string encode(vector<string>& strs) {
         std::string result;

        for (const auto& str : strs) {
            int n = str.size();
            result += "#" + std::to_string(n) + "#";
            result += str;
        }

        return result;
    }

    vector<string> decode(string s) {
        if (s.empty()) {
        return {};
        }

        if (s[0] != '#') {
            return {};
        }

        if (s.size() <= 1) {
            return {s};
        }

        std::vector<std::string> result;

        for (int i = 1; i < s.size(); ++i) {
            if (s[i-1] == '#') {
                std::string size_str;
                while (std::isdigit(s[i]) && s[i] != '#') {
                    size_str += s[i++];
                }

                i++;
                int size = std::stoi(size_str);

                std::string tmp;
                for (int j = 0; j < size; j++) {
                    tmp += s[i + j];
                }
                result.push_back(tmp);
                i += size;
            }
        }

        return result;
    }
};
