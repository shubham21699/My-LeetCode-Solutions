class UndergroundSystem {
    map<int, pair<string, int>> check;
    map<pair<string, string>, vector<int>> avg;
    
public:
    UndergroundSystem() {
        check.clear();
        avg.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        check[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        int diff = t - check[id].second;
        avg[{ check[id].first, stationName }].push_back(diff);
        check.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        
        vector<int> v = avg[{ startStation, endStation }];
        double ans = 0.0;
        
        for(int i=0 ; i<v.size() ; i++) ans += v[i];
        
        ans /= v.size();
        return ans;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */