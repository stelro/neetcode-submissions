class PrefixTree {
private:
	struct Node {
		std::unordered_map<char, Node*> node;
		bool end = false;
	};
	Node* head;
public:
    PrefixTree() {
        head = new Node();
    }
    
    void insert(std::string word) {

        Node* current = head;

		for (int i = 0; i < word.size(); i++) {
			Node* new_node = nullptr;
			auto it = current->node.find(word[i]);
			if (it != current->node.end()) {
				new_node = it->second;
			} else {
				new_node = new Node();
			}

			if (i == word.size() - 1) {
				new_node->end = true;
			}
			current->node.insert({word[i], new_node});
			current = new_node;
			
		}

    }
    
    bool search(std::string word) {
        Node* current = head;
    	for (auto c : word) {
    		auto it = current->node.find(c);
    		if (it == current->node.end()) {
    			return false;
    		}
    		current = it->second;
    	}

    	return current->end;
    }
    
    bool startsWith(std::string prefix) {
    	Node* current = head;
        for (auto c : prefix) {
        	auto it = current->node.find(c);
        	if (it == current->node.end()) {
        		return false;
        	}
        	current = it->second;
        }
    	return true;
    }
};