class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n == 1) return {0};
        
        vector<int> graph[n];
        vector<int> degrees(n, 0);
        
        for(int i=0 ; i<edges.size() ; i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            degrees[edges[i][0]]++;
            degrees[edges[i][1]]++;
        }
        
        // BFS Approach:
        queue<int> q;
        
        for(int i=0 ; i<n ; i++) {
            // Adding all the leaf nodes
            if(degrees[i] == 1) q.push(i);
        }
        
        vector<int> result;
        
        while(!q.empty()) {
            
            result.clear(); // Clear vector before we start traversing level by level.
            int size = q.size();
            
            while(size--) {
                
                int currentEle = q.front();
                q.pop();
                
                // Adding nodes to vector.
                // Goal is to get a vector of just 1 or 2 nodes available.
                result.push_back(currentEle);
                
                for(auto neighbor : graph[currentEle]) {
                    degrees[neighbor]--; // Removing current leave nodes
                    if(degrees[neighbor] == 1) q.push(neighbor); // Adding current leave nodes
                }
                
            }
            
        }
        
        return result;
    }
};