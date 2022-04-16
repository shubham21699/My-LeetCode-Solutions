class TimeMap {
    unordered_map<string, vector<pair<int, string>>> mp;
    
public:
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({ timestamp, value });
    }
    
    string get(string key, int timestamp) {
        
        if(mp.find(key) == mp.end()) return "";
        
        int start = 0;
        int end = mp[key].size();
        
        while(start < end) {
            
            int mid = start + (end - start)/2;
            
            if(mp[key][mid].first > timestamp) end = mid;
            else start = mid+1;
            
        }
        
        return start>0 && start<=mp[key].size() ? mp[key][start-1].second : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */