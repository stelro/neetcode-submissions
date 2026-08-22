class LRUCache {
private:
    using Bucket = std::pair<int, int>;
    std::list<Bucket> cache_;
    std::unordered_map<int, typename std::list<Bucket>::iterator> map_;
    int capacity = 0;
public:
    LRUCache(int c) : capacity(c) { }
    
    int get(int key) {
       auto it = map_.find(key);
       if (it == map_.end()) {
            return -1;
       } 

       cache_.splice(cache_.begin(), cache_, it->second);
       return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = map_.find(key);
        if (it != map_.end()) {
            it->second->second = value;
            cache_.splice(cache_.begin(), cache_, it->second);
            return;
        }

        cache_.emplace_front(key, value);
        map_[key] = cache_.begin();

        if (cache_.size() > capacity) {
            auto node = cache_.back();
            map_.erase(node.first);
            cache_.pop_back();
        }
    }
};
