class MyCalendarThree {
public:
    map<int, int> mp;
    
    MyCalendarThree() {
        mp.clear();
    }
    
    int book(int start, int end) {
        
        int count = 0;
        int maxi = 0;
        mp[start]++;
        mp[end]--;
        
        for(auto it=mp.begin() ; it!=mp.end() ; it++) {
            count += it->second;
            maxi = max(maxi, count);
        }
        
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */