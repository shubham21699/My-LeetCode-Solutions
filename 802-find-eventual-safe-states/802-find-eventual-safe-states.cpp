class Solution {
    bool dfs(vector<vector<int>>& graph, vector<int>& safeOrNot, int current_node) {
        
        // We mainly have to check if a cycle exists in current_node path or not
        // If safeOrNot[i] = 0, then it is an unvisited node
        // If safeOrNot[i] = 1, then it is a visited and unsafe node means cycle exists
        // If safeOrNot[i] = 2, then it is a visited and safe node means there is no cycle 
        // and ending path node is a terminal node.
        
        safeOrNot[current_node] = 1; // Initially take it as an unsafe node.
        
        for(auto node : graph[current_node]) {
            
            if(safeOrNot[node] == 1 || (safeOrNot[node] == 0 && !dfs(graph, safeOrNot, node))) {
                return false;
            }
            
        }
        
        safeOrNot[current_node] = 2; // If there is no cycle, mark it as safe node.
        return true;
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> result;
        vector<int> safeOrNot(n, 0);
        
        // if node is visited and safe OR unvisited and does not contain a cycle, then add it to result
        for(int i=0 ; i<n ; i++) {
            if(safeOrNot[i] == 2 || dfs(graph, safeOrNot, i)) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};