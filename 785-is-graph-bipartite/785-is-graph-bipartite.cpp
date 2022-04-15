class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        // We are trying to split the graph into two groups of edges.
        // So we color the edges, lets say 1=red, -1=blue, 0=noColor
        // A graph is bipartite if and only if two ends of each edge have different colors.
        
        int n = graph.size();
        vector<int> color(n, 0);
        queue<int> q;
        
        for(int i=0 ; i<n ; i++) {
            
            if(color[i]) continue;
            
            color[i] = 1; // Color it Red.
            q.push(i);
            
            while(!q.empty()) {
                
                int temp = q.front();
                
                for(auto neighbor : graph[temp]) {
                    
                    if(!color[neighbor]) {
                        color[neighbor] = -color[temp]; // Color its neighbors Blue.
                        q.push(neighbor);
                    }
                    else if(color[neighbor] == color[temp]) {
                        return false;
                    }
                    
                }
                
                q.pop();
            }
            
        }
        
        return true;
    }
};