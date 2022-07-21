class LFUCache {
public:
    unordered_map<int, pair<int, int>> mp; // key to {value,freq}
    unordered_map<int, list<int>::iterator> lt; // key to list iterator
    unordered_map<int, list<int>> fr; // Freq to key list
    int cap = 0;
    int size = 0;
    int minFreq;
    
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    
    int get(int key) {
        
        if(mp.find(key) == mp.end()) return -1;
        
        fr[mp[key].second].erase(lt[key]);
        mp[key].second++;
        fr[mp[key].second].push_back(key);
        lt[key] = --fr[mp[key].second].end();
        
        if(fr[minFreq].size() == 0) minFreq++;
        
        return mp[key].first;
    }
    
    void put(int key, int value) {
        
        if(cap == 0) return;
        
        if(mp.find(key) != mp.end()) {
            get(key);
            mp[key].first = value;
            return;
        }
        
        if(size == cap) {
            
            mp.erase(fr[minFreq].front());
            lt.erase(fr[minFreq].front());
            fr[minFreq].pop_front();
            size--;
            
        }
        
        mp[key] = { value, 1 };
        fr[1].push_back(key);
        lt[key] = --fr[1].end();
        minFreq = 1;
        size++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */