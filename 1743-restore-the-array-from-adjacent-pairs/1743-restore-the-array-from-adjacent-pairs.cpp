class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        
        int n = adjacentPairs.size();
        if(n == 1) return adjacentPairs[0];
        
        unordered_map<int, bool> visited;
        unordered_map<int, vector<int>> graph;
        vector<int> result;
   
        for(int i=0 ; i<n ; i++) {
            graph[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            graph[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }
        
        int start = 0;
        for(auto it=graph.begin() ; it!=graph.end() ; it++) {
            if(it->second.size() == 1) {
                start = it->first;
                break;
            }
        }
        
        while(!visited[start]) {
            
            result.push_back(start);
            visited[start] = true;
            
            for(auto val : graph[start]) {
                if(!visited[val]) {
                    start = val;
                    break;
                }
            }
            
        }
        
        return result;
    }
};