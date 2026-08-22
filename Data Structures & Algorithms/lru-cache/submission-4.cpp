class LRUCache {
	using bucket_t = std::pair<int, int>;
public:
    LRUCache(int capacity) : capacity_ {capacity} { }

    int get(int key) {

		if (cache_.find(key) == cache_.end()) {
			return -1;
		}
	
		auto bucket = cache_[key];
		buckets_.splice(buckets_.begin(), buckets_, bucket);
		return bucket->second;
    }
    
    void put(int key, int value) {

		if (cache_.find(key) != cache_.end()) {
			auto it = cache_[key];
			it->second = value;
			buckets_.splice(buckets_.begin(), buckets_, it);
			return;
		}

    	buckets_.push_front({key, value});
		auto front = buckets_.begin();
		cache_[key] = front;

		if (buckets_.size() > capacity_) {
			auto back = buckets_.back();
			cache_.erase(back.first);
			buckets_.pop_back();
		}
    }


private:
	std::list<bucket_t> buckets_;
	std::unordered_map<int, typename std::list<bucket_t>::iterator> cache_;
	int capacity_ {0};
};