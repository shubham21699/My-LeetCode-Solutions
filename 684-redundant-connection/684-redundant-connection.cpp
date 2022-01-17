class Solution {
    unordered_set<int> s; // Will store all the nodes of cycle
    int cycleStart = -1; // Marke the start node of cycle
    
    void isCycle(int v, vector<bool>& visited, int parent, vector<vector<int> > graph) {
     
        if(visited[v]) { // If reached already visited node, means its in cycle amd mark as start of cycle
            cycleStart = v;
            return;
        }
        
        visited[v] = true; // If visited 1st time, marked as visited
        
        // Iterate over adjacent nodes of current node
        for(auto node : graph[v]) {
            
            // Do not visit parent again
            if(node == parent) continue;
            
            // If cycle not yet detected, explore graph further
            if(s.empty()) isCycle(node, visited, v, graph);
            
            // If cycle is detected, keep pushing nodes untill we reach the start of cycle
            if(cycleStart != -1) s.insert(v);
            
            // If all the nodes of cycle are taken, then just returns
            if(v == cycleStart) {
                cycleStart = -1;
                return;
            }
            
        }
        
    }
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        vector<vector<int> > graph(n+1);
        vector<bool> visited(n+1, false);
        
        // Constructing graph
        for(int i=0 ; i<n ; i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        isCycle(1, visited, -1, graph); // dfs traversal to detect cycle and fill those nodes in cycle set
        
        for(int i=n-1 ; i>=0 ; i--) {
            // Last edge of input present in the cycle
            if(s.count(edges[i][0]) >= 1 && s.count(edges[i][1]) >= 1) return edges[i];
        }
        
        return {}; // If unreachable
        
    }
};