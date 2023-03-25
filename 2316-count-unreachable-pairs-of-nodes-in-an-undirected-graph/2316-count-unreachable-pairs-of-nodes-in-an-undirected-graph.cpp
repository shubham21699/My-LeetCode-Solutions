class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& graph, int node, vector<bool>& visited, unordered_set<int>& st) {
        
        visited[node] = true;
        st.insert(node);
        
        for(auto next : graph[node]) {
            if(!visited[next]) dfs(graph, next, visited, st);
        }
        
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        int m = edges.size();
        unordered_map<int, vector<int>> graph;
        
        for(int i=0 ; i<m ; i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool> visited(n);
        long long count = 0;
        
        for(int i=0 ; i<n ; i++) {
            if(!visited[i]) {
                unordered_set<int> st;
                dfs(graph, i, visited, st);
                count += (long long) int(st.size()) * (long long) (n - int(st.size()));
            }
        }

        return count / 2;
    }
};