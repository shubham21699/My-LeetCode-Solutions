class Solution {
public:
    int dfs(unordered_map<int, vector<int>>& graph, int curr, unordered_set<int>& visited, vector<int>& values, int k, int& count) {
        
        visited.insert(curr);
        
        for(auto next : graph[curr]) {
            if(visited.find(next) == visited.end()) {
                values[curr] += dfs(graph, next, visited, values, k, count);
            }
        }
        
        if(values[curr] % k == 0) {
            count++;
            return 0;
        }
        
        return values[curr];
    }
    
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        
        int m = edges.size();
        unordered_map<int, vector<int>> graph;
        
        for(int i=0 ; i<m ; i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        unordered_set<int> visited;
        int count = 0;
        dfs(graph, 0, visited, values, k, count);
        
        return count;
    }
};