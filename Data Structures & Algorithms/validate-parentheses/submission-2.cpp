class Solution {
public:
    bool isValid(string s) {
        std::stack<char> seq;
        for (const char& c : s) {
            if (c == '[' || c == '(' || c == '{') {
                seq.push(c);
            }
            else if ((c == ']' || c == ')' || c == '}') && !seq.empty()) {
                auto back = seq.top();
                if ((back == '[' && c == ']') ||
                    (back == '(' && c == ')') ||
                    (back == '{' && c == '}')) {
                        seq.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
        return seq.empty();
    }
};
