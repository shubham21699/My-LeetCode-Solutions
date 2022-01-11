class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        int n = trips.size();
        sort(trips.begin(), trips.end(), [] ( const vector<int>& a, const vector<int>& b ){
            if(a[1] == b[1]) return a[2] < b[2];
            return a[1] < b[1];
        });
        
        int current = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        
        for(int i=0 ; i<n ; i++) {
            
            while(!pq.empty() && pq.top().first <= trips[i][1]) {
                current -= pq.top().second;
                pq.pop();
            }
            
            pq.push({ trips[i][2], trips[i][0] });
            current += trips[i][0];
            
            if(current > capacity) return false;
            
        }
        
        return true;
    }
};