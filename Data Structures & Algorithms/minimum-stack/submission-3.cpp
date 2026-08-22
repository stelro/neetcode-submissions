class MinStack {
private:
  std::stack<std::pair<int, int>> stack_;
public:
  MinStack() {}
  void push(int val) {
	int min_ = std::min(stack_.empty() ? std::numeric_limits<int>::max() : stack_.top().second, val);
    stack_.push({val, min_});
  }

  void pop() {
    stack_.pop();
  }

  int top() { 
	  return stack_.top().first; 
  }

  int getMin() { 
	  return stack_.top().second; 
  }
};