class Solution {
public:    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        int n = edges.size();
        vector<int> graph[n];
        
        for(int i=0 ; i<n ; i++) {
            if(edges[i] != -1) graph[i].push_back(edges[i]);
        }
        
        vector<int> v1(n, INT_MAX), v2(n, INT_MAX);
        vector<bool> visited1(n), visited2(n);
        v1[node1] = 0;
        v2[node2] = 0;
        
        queue<int> q;
        q.push(node1);
        
        while(!q.empty()) {
            
            int curr = q.front();
            q.pop();
            visited1[curr] = true;
            
            for(auto node : graph[curr]) {
                if(!visited1[node]) {
                    v1[node] = v1[curr] + 1;
                    q.push(node);
                }
            }
            
        }
        
        q.push(node2);
        
        while(!q.empty()) {
            
            int curr = q.front();
            q.pop();
            visited2[curr] = true;
            
            for(auto node : graph[curr]) {
                if(!visited2[node]) {
                    v2[node] = v2[curr] + 1;
                    q.push(node);
                }
            }
            
        }
        
        int result = -1;
        int minDist = INT_MAX;
        
        for(int i=0 ; i<n ; i++) {
            if(v1[i] != INT_MAX && v2[i] != INT_MAX) {
                int nodeDist = max(v1[i], v2[i]);
                if(minDist > nodeDist) {
                    minDist = nodeDist;
                    result = i;
                }
            }
        }
        
        return result;
    }
};