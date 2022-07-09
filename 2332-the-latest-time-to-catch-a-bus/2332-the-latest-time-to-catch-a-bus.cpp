class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        
        int n = buses.size();
        int m = passengers.size();
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        
        if(n == 1 && m == 1) {
            if(capacity == 1) return passengers[0]-1;
            return passengers[0] == buses[0] ? passengers[0]-1 : buses[0];
        }
        
        unordered_set<int> st;
        for(int j=0 ; j<m ; j++) st.insert(passengers[j]);
        
        
        int ans = passengers[0]-1;
        int j = 0;
        
        for(int i=0 ; i<n ; i++) {
            int cap = capacity;
            while(cap > 0 && j < m && passengers[j] <= buses[i]) {
                ans = passengers[j];
                cap--;
                j++;
            }
            
            if(cap) ans = buses[i];
        }
        
        while(st.find(ans) != st.end()) ans--;
         
        return ans;
    }
};