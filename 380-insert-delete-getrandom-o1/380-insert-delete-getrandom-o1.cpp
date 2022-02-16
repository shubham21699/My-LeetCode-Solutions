class RandomizedSet {
    unordered_map<int, int> m;
    vector<int> v;
    
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        
        if(m.find(val) == m.end()) { // If not present
            v.push_back(val);
            m[val] = v.size()-1;
            return true;
        }
        
        return false;
    }
    
    bool remove(int val) {
        
        if(m.find(val) != m.end()) { // If present
            // Interchange values with val and last element of both vector and map
            // and remove last element of vector and val from map.
            m[v.back()] = m[val];
            v[m[val]] = v.back();
            v.pop_back();
            m.erase(val);
            return true;
        }
        
        return false;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */