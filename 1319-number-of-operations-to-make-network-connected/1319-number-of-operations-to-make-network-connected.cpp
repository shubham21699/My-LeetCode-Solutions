class Solution {
    void dfs(unordered_map<int, vector<int>>& graph, vector<bool>& visited, int current_node) {
        
        visited[current_node] = true;
        
        for(int node : graph[current_node]) {
            if(!visited[node]) {
                dfs(graph, visited, node);
            }
        }
        
    }
    
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int m = connections.size();
        if(n-1 > m) return -1;
        
        unordered_map<int, vector<int>> graph;
        
        for(int i=0 ; i<m ; i++) {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        
        vector<bool> visited(n, false);
        int count = 0;
        
        for(int i=0 ; i<n ; i++) {
            if(!visited[i]) {
                dfs(graph, visited, i);
                count++;
            }
        }
        
        return count-1;
    }
};