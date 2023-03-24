class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        int m = connections.size();
        unordered_map<int, set<int>> dirGraph, unDirGraph;
        
        for(int i=0 ; i<m ; i++) {
            dirGraph[connections[i][1]].insert(connections[i][0]);
            
            unDirGraph[connections[i][0]].insert(connections[i][1]);
            unDirGraph[connections[i][1]].insert(connections[i][0]);
        }
        
        int count = 0;
        vector<bool> visited(n);
        visited[0] = true;
        queue<int> q;
        q.push(0);
        
        while(!q.empty()) {
            
            int currCity = q.front();
            q.pop();
            
            for(auto nextCity : unDirGraph[currCity]) {
                if(!visited[nextCity]) {
                    if(dirGraph[currCity].find(nextCity) == dirGraph[currCity].end()) count++;
                    q.push(nextCity);
                    visited[nextCity] = true;
                }
            }
            
        }
        
        return count;
    }
};