class LRUCache {
    // key value
    using bucket_t = std::pair<int, int>;
public:
    LRUCache(int capacity) : capacity_ {capacity} {
        
    }
    
    int get(int key) {
        auto it = hash_map_.find(key);
        if (it != hash_map_.end()) {
            buckets_.splice(buckets_.begin(), buckets_, it->second);
            return it->second->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = hash_map_.find(key);
        if (it != hash_map_.end()) {
            it->second->second = value;
            buckets_.splice(buckets_.begin(), buckets_, it->second);
            return;
        }

        buckets_.push_front({key, value});
        hash_map_[key] = buckets_.begin();

        if (buckets_.size() > capacity_) {
            auto last = buckets_.back();
            hash_map_.erase(last.first);
            buckets_.pop_back();
        }
    }
private:
    std::list<bucket_t> buckets_;
    std::unordered_map<int, typename std::list<bucket_t>::iterator> hash_map_;
    size_t capacity_ {0};
};
