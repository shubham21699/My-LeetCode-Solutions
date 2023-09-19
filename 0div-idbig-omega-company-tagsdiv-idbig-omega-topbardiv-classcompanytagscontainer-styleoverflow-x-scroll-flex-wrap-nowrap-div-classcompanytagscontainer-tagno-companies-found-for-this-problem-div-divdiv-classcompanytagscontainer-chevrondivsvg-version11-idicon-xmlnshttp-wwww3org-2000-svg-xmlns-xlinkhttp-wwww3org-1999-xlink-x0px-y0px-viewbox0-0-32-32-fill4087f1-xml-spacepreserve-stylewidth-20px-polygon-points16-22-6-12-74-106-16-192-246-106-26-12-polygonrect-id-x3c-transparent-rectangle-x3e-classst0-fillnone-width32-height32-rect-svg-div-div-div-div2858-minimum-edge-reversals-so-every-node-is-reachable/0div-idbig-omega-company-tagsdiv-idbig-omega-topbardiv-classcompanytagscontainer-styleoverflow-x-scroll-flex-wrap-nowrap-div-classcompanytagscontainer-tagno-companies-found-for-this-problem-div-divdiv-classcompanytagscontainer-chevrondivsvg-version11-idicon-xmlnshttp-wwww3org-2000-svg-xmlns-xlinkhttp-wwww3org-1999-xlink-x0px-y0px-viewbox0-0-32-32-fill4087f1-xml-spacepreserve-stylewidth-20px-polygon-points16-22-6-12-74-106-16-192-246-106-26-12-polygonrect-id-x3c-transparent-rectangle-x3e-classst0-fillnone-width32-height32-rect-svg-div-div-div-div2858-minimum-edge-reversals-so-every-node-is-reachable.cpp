class Solution {
public:
    int dfs(unordered_map<int, unordered_set<int>>& graph, unordered_map<int, unordered_set<int>>& revGraph, int currNode, int parent, map<pair<int, int>, int>& dp) {
        
        if(dp.find({ currNode, parent }) != dp.end()) return dp[{ currNode, parent }];
        
        int count = 0;
        
        for(auto next : graph[currNode]) {
            if(next != parent) count += dfs(graph, revGraph, next, currNode, dp);
        }
        
        for(auto next : revGraph[currNode]) {
            if(next != parent) count += 1 + dfs(graph, revGraph, next, currNode, dp);
        }
        
        return dp[{ currNode, parent }] = count;
    }
    
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        
        unordered_map<int, unordered_set<int>> graph, revGraph;
        
        for(int i=0 ; i<n-1 ; i++) {
             graph[edges[i][0]].insert(edges[i][1]);
             revGraph[edges[i][1]].insert(edges[i][0]);
        }
        
        map<pair<int, int>, int> dp;
        vector<int> result(n);
        
        for(int i=0 ; i<n ; i++) {
            result[i] = dfs(graph, revGraph, i, -1, dp);
        }
        
        return result;
        
        
//         // OR: Will give TLE for last case with n=10^5
//         unordered_map<int, unordered_set<int>> dir, undir;
        
//         for(int i=0 ; i<n-1 ; i++) {
//             dir[edges[i][0]].insert(edges[i][1]);
            
//             undir[edges[i][0]].insert(edges[i][1]);
//             undir[edges[i][1]].insert(edges[i][0]);
//         }
        
//         vector<int> result(n);
        
//         for(int i=0 ; i<n ; i++) {
            
//             int count = 0;
//             unordered_set<int> visited;
//             queue<int> q;
//             q.push(i);
//             visited.insert(i);
            
//             while(!q.empty()) {
                    
//                 auto curr = q.front();
//                 q.pop();
                    
//                 for(auto next : undir[curr]) {
//                     if(visited.find(next) == visited.end()) {
//                         if(dir[curr].find(next) == dir[curr].end()) count++;
                            
//                         visited.insert(next);
//                         q.push(next);
//                     }
//                 }
                
//             }
            
//             result[i] = count;
//         }
     
//         return result;
    }
};