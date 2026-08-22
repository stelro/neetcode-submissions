class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stack;
        for (auto token : tokens) {
            if (token == "+" || token == "*" || token == "-" || token ==  "/") {
                auto right = stack.top(); stack.pop();
                auto left = stack.top(); stack.pop();
                if (token == "+") stack.push(left + right);
                if (token == "-") stack.push(left - right);
                if (token == "*") stack.push(left * right);
                if (token == "/") stack.push(left / right);
            } else {
                stack.push(std::stoi(token));
            }
        }
        
        return stack.empty() ? 0 : stack.top();
    }
};
