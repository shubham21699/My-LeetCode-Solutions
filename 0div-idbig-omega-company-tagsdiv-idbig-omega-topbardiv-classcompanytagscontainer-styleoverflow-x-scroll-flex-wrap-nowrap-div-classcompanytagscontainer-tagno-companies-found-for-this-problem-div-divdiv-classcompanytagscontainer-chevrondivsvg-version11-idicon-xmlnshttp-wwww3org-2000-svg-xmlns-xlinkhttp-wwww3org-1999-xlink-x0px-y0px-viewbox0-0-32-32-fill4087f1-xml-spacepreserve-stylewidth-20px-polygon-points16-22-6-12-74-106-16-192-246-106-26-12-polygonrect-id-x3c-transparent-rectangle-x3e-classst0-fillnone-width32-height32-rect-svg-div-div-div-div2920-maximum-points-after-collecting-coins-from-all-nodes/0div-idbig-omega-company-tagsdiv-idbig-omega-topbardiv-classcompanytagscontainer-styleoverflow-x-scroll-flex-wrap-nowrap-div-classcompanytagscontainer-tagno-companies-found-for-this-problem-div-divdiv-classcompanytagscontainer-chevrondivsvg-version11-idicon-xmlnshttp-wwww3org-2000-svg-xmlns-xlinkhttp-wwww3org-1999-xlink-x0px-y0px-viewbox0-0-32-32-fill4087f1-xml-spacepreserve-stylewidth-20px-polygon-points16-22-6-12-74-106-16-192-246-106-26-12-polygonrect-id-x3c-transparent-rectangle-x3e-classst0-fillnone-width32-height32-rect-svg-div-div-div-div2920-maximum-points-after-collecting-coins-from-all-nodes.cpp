class Solution {
public:
    int dfs(unordered_map<int, vector<int>>& graph, int node, int parent, vector<int>& coins, int k, vector<int>& visited, int div) {
        
        if(div > 10000 || visited[node] & div) return 0;
        
        visited[node] |= div;
        
        int op1 = (coins[node] / div) - k;
        int op2 = coins[node] / (div * 2);
        
        for(auto next : graph[node]) {
            if(next != parent) {
                
                op1 += dfs(graph, next, node, coins, k, visited, div);
                op2 += dfs(graph, next, node, coins, k, visited, div * 2);

            }
        }
        
        return max(op1, op2);
    }
    
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        
        int n = coins.size();
        int m = edges.size();
        
        unordered_map<int, vector<int>> graph;
        
        for(int i=0 ; i<m ; i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> visited(n+1);
        
        return dfs(graph, 0, -1, coins, k, visited, 1);
    }
};