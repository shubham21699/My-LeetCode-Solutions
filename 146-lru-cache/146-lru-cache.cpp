class LRUCache {
public:
    unordered_map<int, pair<list<int>::iterator, int>> m;
    list<int> l;
    int max_capacity = 0;
    
    LRUCache(int capacity) {
        m.clear();
        l.clear();
        max_capacity = capacity;
    }
    
    int get(int key) {
        
        if(m.find(key) != m.end()) {
            
            l.erase(m[key].first);
            l.push_front(key);
            m[key].first = l.begin();
            
            return m[key].second;
        }
        
        return -1; 
    }
    
    void put(int key, int value) {
        
        // If already present, then update it
        if(m.find(key) != m.end()) {
            
            m[key].second = value;
            
            l.erase(m[key].first);
            l.push_front(key);
            m[key].first = l.begin();
            
        }
        
        else {
            
            l.push_front(key);
            m[key].first = l.begin();
            m[key].second = value;
            max_capacity--;
            
        }
        
        if(max_capacity < 0) {
            
            m.erase(l.back());
            l.pop_back();
            max_capacity++;
            
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */