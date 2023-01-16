class Solution {
public:
    long long pathSum(unordered_map<int, vector<int>>& graph, int node, int parent, vector<int>& price, vector<unordered_map<int, long long>>& dp) {
        
        if(dp[node].count(parent)) return dp[node][parent];
        
        long long sum = 0;
        
        for(auto child : graph[node]) {
            if(child != parent) {
                sum = max(sum, pathSum(graph, child, node, price, dp));
            }
        }
        
        return dp[node][parent] = sum + price[node];
    }
    
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        
        int m = edges.size();
        unordered_map<int, vector<int>> graph(n);
        
        for(int i=0 ; i<m ; i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        long long result = 0;
        vector<unordered_map<int, long long>> dp(n);
        
        for(int i=0 ; i<n ; i++) {
            if(graph[i].size() == 1) {
                long long PS = pathSum(graph, i, -1, price, dp);
                result = max(result, PS - price[i]);
            }
        }
        
        return result;
    }
};