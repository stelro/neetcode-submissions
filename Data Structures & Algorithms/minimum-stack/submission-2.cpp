class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        min_so_far = std::min(val, min_so_far);
        stack.push_back({val, min_so_far});
    }
    
    void pop() {
        node back = stack.back();
        stack.pop_back();
        if (back.first == back.second) {
            min_so_far = stack.back().second;
        }
        if (stack.empty()) {
            min_so_far = std::numeric_limits<int>::max();
        }
    }
    
    int top() {
        return stack.back().first;
    }
    
    int getMin() {
        return stack.back().second;
    }

private:
    using node = std::pair<int, int>; // value, min_value
    
    std::vector<node> stack;
    int min_so_far{std::numeric_limits<int>::max()};
};
