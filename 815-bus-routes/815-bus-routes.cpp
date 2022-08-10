class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        int n = routes.size();
        unordered_map<int, set<int>> graph;
        
        for(int i=0 ; i<n ; i++) {
            for(int nextStop : routes[i]) {
                graph[nextStop].insert(i);
            }
        }
        
        queue<pair<int, int>> q;
        q.push({ source, 0 });
        unordered_map<int, bool> visited;
        visited[source] = true;
        
        while(!q.empty()) {
            
            int curr = q.front().first;
            int busesToChange = q.front().second;
            q.pop();
            
            if(curr == target) return busesToChange;
            
            for(auto nextStop : graph[curr]) {
                for(auto nextBus : routes[nextStop]) {
                    if(visited.find(nextBus) == visited.end()) {
                        q.push({ nextBus, busesToChange+1 });
                        visited[nextBus] = true;
                    }
                }
                
                routes[nextStop].clear();
            }
            
        }
        
        return -1;
    }
};