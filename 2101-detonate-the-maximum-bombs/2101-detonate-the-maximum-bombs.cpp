class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, int currBomb) {
        
        for(auto nextBomb : graph[currBomb]) {
            if(visited.find(nextBomb) == visited.end()) {
                visited.insert(nextBomb);
                dfs(graph, visited, nextBomb);
            }
        }
        
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int n = bombs.size();
        unordered_map<int, vector<int>> graph;
        int result = 0;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(i != j) {
                    
                    if(pow(bombs[i][2], 2) >= pow(bombs[j][0] - bombs[i][0], 2) + pow(bombs[j][1] - bombs[i][1], 2)) {
                        graph[i].push_back(j);
                    }
                    
                }
            }
        }
        
        for(int i=0 ; i<n ; i++) {
            unordered_set<int> visited;
            visited.insert(i);
            dfs(graph, visited, i);
            result = max(result, int(visited.size()));
        }
        
        return result;
    }
};