class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        
        int n = values.size();
        int m = values[0].size();
        long long spending = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                pq.push(values[i][j]);
            }
        }
        
        int d = 1;
        
        while(!pq.empty()) {
            int val = pq.top();
            pq.pop();
            
            spending += (1LL * val * d);
            d++;
        }
        
        return spending;
    }
};