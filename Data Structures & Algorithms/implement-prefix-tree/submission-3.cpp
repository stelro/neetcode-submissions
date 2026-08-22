class PrefixTree {
public:
    PrefixTree() {
    	head = new Node();
    }

	// tea -> t -> e -> a -> last word = true
    
    void insert(std::string word) {
		Node* current = head;
    	for (int i = 0; i < word.size(); i++) {
    		Node* temp = nullptr;
    		int x = word[i] - 'a';
    		if (current->children[x] != nullptr) {
    			temp = current->children[x];
    		} else {
    			temp = new Node();
    		}

    		if (i == word.size() - 1) {
    			temp->end = true;
    		}

    		current->children[x] = temp;
    		current = temp;
    	}
    }
    
    bool search(std::string word) {
		Node* curr = head;
    	for (auto c : word) {
    		auto i = c - 'a';
    		if (curr->children[i] == nullptr) {
    			return false;
    		}
    		curr = curr->children[i];
    	}
    	return curr->end;
    }
    
    bool startsWith(std::string prefix) {
		Node* curr = head;
    	for (auto c : prefix) {
    		auto i = c - 'a';
    		if (curr->children[i] == nullptr) {
    			return false;
    		}
    		curr = curr->children[i];
    	}
    	return true;
    }
private:
	struct Node {
		Node() {
			children.assign(26, nullptr);
		}
		std::vector<Node*> children = std::vector<Node*>(26, nullptr);
		bool end = false;
	};

	Node* head;
};