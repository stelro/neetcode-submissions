class LRUCache {
public:
    LRUCache(int capacity) : capacity_ {capacity} { }

    int get(int key) {
		auto it = map_.find(key);
		if (it == map_.end()) {
			return -1;
		}
		buckets_.splice(buckets_.begin(), buckets_, it->second);
		return it->second->value;
    }
    
    void put(int key, int value) {
		auto it = map_.find(key);
		if (it != map_.end()) {
			it->second->value = value;
			buckets_.splice(buckets_.begin(), buckets_, it->second);
			return;
		}
		
		buckets_.emplace_front(key, value);
		map_[key] = buckets_.begin();

		if (map_.size() > capacity_) {
			auto back = buckets_.back();
			map_.erase(back.key);
			buckets_.pop_back();
		}
    }
private:
	struct Bucket { int key, value; };
	std::list<Bucket> buckets_;
	std::unordered_map<int, std::list<Bucket>::iterator> map_;
	int capacity_ {0};
};