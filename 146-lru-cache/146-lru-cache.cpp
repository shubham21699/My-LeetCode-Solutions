class LRUCache {
public:
    // unordered_map<int, pair<list<int>::iterator, int>> m;
    // list<int> l;
    // int max_capacity = 0;
    list<pair<int, int>> lst;
    // Pair of key, value
    
    // Hashtable
    vector<list<pair<int, int>>::iterator> hshtable;
    int mxLimit;
    
    LRUCache(int capacity) {
        // m.clear();
        // l.clear();
        // max_capacity = capacity;
        mxLimit = capacity;
        lst.clear();
        hshtable.clear();
        hshtable.resize(10001);
        fill(hshtable.begin(), hshtable.end(), lst.end());
    }
    
    int get(int key) {
        
        if(hshtable[key] != lst.end()) {
            // The value already exists
            // Move it to the back
            auto it = hshtable[key];
            int value = it->second;
            lst.erase(it);
            
            // This value does not exist in the list
            // Add it
            lst.push_back({key, value});
            it = --lst.end();
            hshtable[key] = it;
        }
        
        
        if (hshtable[key] == lst.end()) return -1;
        else {
            return hshtable[key]->second;
        }
        
//         if(m.find(key) != m.end()) {
            
//             l.erase(m[key].first);
//             l.push_front(key);
//             m[key].first = l.begin();
            
//             return m[key].second;
//         }
        
//         return -1; 
    }
    
    void put(int key, int value) {
        
        if(hshtable[key] != lst.end()) {
            // The value already exists
            // Move it to the back
            auto it = hshtable[key];
            lst.erase(it);
        }
        
        // This value does not exist in the list
        // Add it
        lst.push_back({key, value});
        auto it = --lst.end();
        hshtable[key] = it;
        
        if (lst.size() > mxLimit) {
            // We need to pop the value from the front
            auto it = lst.begin();
            hshtable[it->first] = lst.end();

            lst.pop_front();
        }

        
//         // If already present, then update it
//         if(m.find(key) != m.end()) {
            
//             m[key].second = value;
            
//             l.erase(m[key].first);
//             l.push_front(key);
//             m[key].first = l.begin();
            
//         }
        
//         else {
            
//             l.push_front(key);
//             m[key].first = l.begin();
//             m[key].second = value;
//             max_capacity--;
            
//         }
        
//         if(max_capacity < 0) {
            
//             m.erase(l.back());
//             l.pop_back();
//             max_capacity++;
            
//         }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */