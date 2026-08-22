class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if (position.empty()) return 0;

	std::map<int, int, std::greater<int>> fleet;
	for (int i = 0; i < position.size(); i++) {
		fleet[position[i]] = speed[i];
	}

	std::stack<float> stack;

	for (const auto& [pos, speed] : fleet) {
		float time_to_arival = ((float)target - pos) / speed;
		if (!stack.empty() && time_to_arival <= stack.top()) {
			// If time to arival of the current car is smaller, then merge
			if (time_to_arival < stack.top()) {
				continue;
				// Keep the smaller car in the stack (the smaller dectates the speed of the fleet)
			}
			stack.pop();
		}

		stack.push(time_to_arival);
	}

    return stack.size();
 
     
    }
};
