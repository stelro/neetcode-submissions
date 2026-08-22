class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else if (c == ')' || c == '}' || c == ']') {
                if (stack.empty()) return false;
                auto top = stack.top();
                if ((top == '(' && c == ')') || 
                    (top == '[' && c == ']') || 
                    (top == '{' && c == '}')) {
                    stack.pop();
                } else {
                    stack.push(c);
                }
            }
	    }

	    return stack.empty();
    }
};
