class Solution {
public:
    int distance(unordered_map<int, vector<int>>& graph, vector<bool>& hasApple, int node, int dist, vector<bool>& visited) {
        
        if(visited[node]) return 0;
        
        visited[node] = true;
        int childCost = 0; // Cost of traversing all children. 
        
        for(auto child : graph[node]) {
            // Check recursively for all apples.
            childCost += distance(graph, hasApple, child, 2, visited);
        }
        
        // If no child has apples, then we won't traverse the subtree, so cost will be zero.
        // similarly, if current node also does not have the apple, we won't traverse this branch at all, 
        // so cost will be zero.
        if(childCost == 0 && hasApple[node] == false) return 0;
        
        // Children has at least one apple or the current node has an apple, so add those costs.
        return childCost + dist;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        int m = edges.size();
        unordered_map<int, vector<int>> graph;
        
        for(int i=0 ; i<m ; i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool> visited(n);
        return distance(graph, hasApple, 0, 0, visited);
    }
};