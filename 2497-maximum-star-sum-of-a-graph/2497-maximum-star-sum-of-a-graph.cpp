class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        
        int n = vals.size();
        int m = edges.size();
        if(n == 1) return vals[0];
        
        unordered_map<int, vector<int>> graph;
        
        for(int i=0 ; i<m ; i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        int result = INT_MIN;
        
        for(int node=0 ; node<n ; node++) {
            
            priority_queue<int> connectedComponents;
            
            for(auto connectedNode : graph[node]) {
                connectedComponents.push(vals[connectedNode]);
            }
            
            int x = k;
            int sum = vals[node];
            result = max(result, sum);
            
            while(!connectedComponents.empty() && x--) {
                sum += connectedComponents.top();
                connectedComponents.pop();
                result = max(result, sum);
            }
            
        }
        
        return result;
    }
};