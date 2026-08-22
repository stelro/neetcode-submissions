class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if (temperatures.empty()) return {};
        std::vector<int> result(temperatures.size(), 0);
        std::stack<int> indicies;
        indicies.push(0);

        for (int i = 1; i < temperatures.size(); i++) {
            
            while (!indicies.empty() && temperatures[i] > temperatures[indicies.top()]) {
                int r = indicies.top();
                indicies.pop();
                result[r] = i - r;
            }

            indicies.push(i);
        }

        return result;
    }
};
