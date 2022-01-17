class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int, int> > graph[n+1];
        vector<int> time(n+1, INT_MAX);
        
        for(int i=0 ; i<times.size() ; i++) {
            graph[times[i][0]].push_back({ times[i][1], times[i][2] }); // source -> { target, weight }
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        pq.push({ 0, k }); // Insert source first itself and initialize its travel time as 0
        time[k] = 0; // initialize source travel time as 0
        
        while(!pq.empty()) {
            
            int current_node = pq.top().second; // source node
            pq.pop();
            
            for(auto node : graph[current_node]) {
                
                int target_node = node.first;
                int target_node_time = node.second;
                
                // If there is shorter path to targeet from source
                if(time[target_node] > time[current_node] + target_node_time) {
                    time[target_node] = time[current_node] + target_node_time;
                    pq.push({ time[target_node], target_node });
                }
                
            }
            
        }
        
        // If time[i] value doesn't change, means that node is not able to be visited so return -1
        for(int i=1 ; i<=n ; i++) {
            if(time[i] == INT_MAX) return -1;
        }
        
        // 0th node is not there because we have from 1 to n, so skip 0th index and return from 1 to n
        return *max_element(time.begin()+1, time.end());
    }
};