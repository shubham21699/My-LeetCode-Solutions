class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        int n = profits.size();
        
        vector<vector<int>> v;
        
        for(int i=0 ; i<n ; i++) {
            v.push_back({ capital[i], profits[i] });
        }
        
        sort(v.begin(), v.end());
        priority_queue<int> pq;
        int maxCapital = w;
        int i = 0, j = 0;
        
        while(i < k) {
            
            while(j < n && v[j][0] <= maxCapital) {
                pq.push(v[j][1]);
                j++;
            }
            
            if(!pq.empty()) {
                maxCapital += pq.top();
                pq.pop();
            }
            
            i++;
        }
        
        return maxCapital;
    }
};