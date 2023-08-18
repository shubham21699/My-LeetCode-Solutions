class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        int m = roads.size();
        unordered_map<int, unordered_set<int>> graph;
        
        for(auto road : roads) {
            graph[road[0]].insert(road[1]);
            graph[road[1]].insert(road[0]);
        }
        
        int result = 0;
        
        for(int i=0 ; i<n-1 ; i++) {
            for(int j=i+1 ; j<n ; j++) {
                int networkRank = graph[i].size() + graph[j].size();
                
                if(graph[i].find(j) != graph[i].end()) networkRank--;
                
                result = max(result, networkRank);
            }
        }
        
        return result;
    }
};