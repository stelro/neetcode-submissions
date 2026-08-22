class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stack;
        for (const auto& token : tokens) {
            int a = 0, b = 0;
            if (token == "+") {
                b = stack.top(); stack.pop();
                a = stack.top(); stack.pop();
                stack.push(a + b);
            } else if (token == "-") {
                b = stack.top(); stack.pop();
                a = stack.top(); stack.pop();
                stack.push(a - b);
            } else if (token == "*") {
                b = stack.top(); stack.pop();
                a = stack.top(); stack.pop();
                stack.push(a * b);
            } else if (token == "/") {
                b = stack.top(); stack.pop();
                a = stack.top(); stack.pop();
                stack.push(a / b);
            } else {
                stack.push(std::stoi(token));
            }
        }
        return stack.top();
    }
};
