class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        int m = relations.size();
        unordered_map<int, vector<int>> graph;
        vector<int> inDegree(n);
        
        for(int i=0 ; i<m ; i++) {
            graph[relations[i][0]-1].push_back(relations[i][1]-1);
            inDegree[relations[i][1]-1]++;
        }
        
        queue<int> q;
        vector<int> dist(n);

        for(int i=0 ; i<n ; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
                dist[i] = time[i];
            }
        }
        
        int result = 0;

        while(!q.empty()) {
            
            int k = q.size();
            
            while(k--) {
                
                int curr = q.front();
                q.pop();
                result = max(result, dist[curr]);
                
                for(auto next : graph[curr]) {
                    dist[next] = max(dist[next], dist[curr] + time[next]);
                    if(--inDegree[next] == 0) q.push(next);
                }
                
            }
            
        }
        
        return result;
    }
};