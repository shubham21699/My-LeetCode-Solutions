class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        int n = tasks.size();
        vector<vector<int>> order;
        
        for(int i=0 ; i<n ; i++) order.push_back({ tasks[i][0], tasks[i][1], i });
        sort(order.begin(), order.end());
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> result;
        int endTime = order[0][0];
        int i = 0;
        
        while(i < n) {
            
            if(!pq.empty()) {
                endTime += pq.top()[0];
                result.push_back(pq.top()[1]);
                pq.pop();
            }
            
            while(i < n && order[i][0] <= endTime) {
                pq.push({ order[i][1], order[i][2], order[i][0] });
                i++;
            }
            
            if(i < n && order[i][0] > endTime && pq.empty()) {
                endTime = order[i][0];
            }
            
        }
        
        while(!pq.empty()) {
            result.push_back(pq.top()[1]);
            pq.pop();
        }
        
        return result;
    }
};