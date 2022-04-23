class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        int m = dislikes.size();
        unordered_map<int, vector<int>> graph;
        vector<bool> visited(n+1, false);
        vector<int> color(n+1, 0); // WHITE: 0, RED: 1, BLUE: 2
        
        for(int i=0 ; i<m ; i++) {
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        for(int i=1 ; i<=n ; i++) {
            
            if(!visited[i]) {
                
                queue<int> q;
                q.push(i);
                color[i] = 1;
                
                while(!q.empty()) {
                    
                    int current = q.front();
                    q.pop();
                    
                    if(visited[current]) continue;
                    visited[current] = true;
                    
                    for(auto node : graph[current]) {
                        
                        if(color[current] == color[node]) return false;
                        if(color[current] == 1) color[node] = 2;
                        else if(color[current] == 2) color[node] = 1;
                        
                        q.push(node);
                    }
                    
                }
                
            }
            
        }
        
        return true;
    }
};