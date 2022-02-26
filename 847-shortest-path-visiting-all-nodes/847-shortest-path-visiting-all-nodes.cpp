class Solution {
    char dp[12][4096] = {};
    
    int dfs(vector<vector<int>>& graph, int visited, int index, int count, int n) {
        
        int result = 2*n;
        if(dp[index][visited] > 0) return dp[index][visited]-1;
        if((visited & (1 << index)) == 0) count++;
        if(count == n) return 0;
        
        if(dp[index][visited] != -1) {
            dp[index][visited] = -1;
            
            for(auto node : graph[index]) {
                result = min(result, 1 + dfs(graph, visited | (1 << index), node, count, n));
            }
            
            dp[index][visited] = result + 1;
        }
        
        return result;
    }
    
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n = graph.size();
        if(n < 4) {
            return n-1;
        }
        
        int result = INT_MAX;
        
        for(auto i=0 ; i<n ; i++) {
            result = min(result, dfs(graph, 0, i, 0, n));
        }
        
        return result;
    }
};