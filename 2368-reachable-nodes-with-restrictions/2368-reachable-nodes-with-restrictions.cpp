class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
        int m = edges.size();
        int k = restricted.size();
        
        unordered_map<int, set<int>> graph;
        for(int i=0 ; i<m ; i++) {
            graph[edges[i][0]].insert(edges[i][1]);
            graph[edges[i][1]].insert(edges[i][0]);
        }
        
        unordered_set<int> st;
        for(int i=0 ; i<k ; i++) st.insert(restricted[i]);
        
        vector<bool> visited(n);
        visited[0] = true;
        
        int count = 0;
        queue<int> q;
        q.push(0);
        
        while(!q.empty()) {
            
            int curr = q.front();
            q.pop();
            count++;
            
            for(auto node : graph[curr]) {
                if(st.find(node) == st.end() && !visited[node]) {
                    q.push(node);
                    visited[node] = true;
                }
            }
        
        }
        
        return count;
    }
};