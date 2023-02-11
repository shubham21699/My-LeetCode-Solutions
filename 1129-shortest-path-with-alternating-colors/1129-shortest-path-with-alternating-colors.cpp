class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        unordered_map<int, vector<pair<int, int>>> graph;
        set<vector<int>> red(redEdges.begin(), redEdges.end());
        set<vector<int>> blue(blueEdges.begin(), blueEdges.end());
        
        for(int i=0 ; i<redEdges.size() ; i++) graph[redEdges[i][0]].push_back({ redEdges[i][1], 0 });
        for(int i=0 ; i<blueEdges.size() ; i++) graph[blueEdges[i][0]].push_back({ blueEdges[i][1], 1 });
        
        bool isPrevRed = false, isPrevBlue = false;
        
        vector<int> result(n, -1);
        result[0] = 0;
        queue<vector<int>> q;
        q.push({ 0, 0, -1 }); // node, dist, color
        
        while(!q.empty()) {
            
            int curr = q.front()[0];
            int dist = q.front()[1];
            int prevEdgeColor = q.front()[2];
            q.pop();
            
            result[curr] = result[curr] == -1 ? dist : result[curr];
            
            for(auto &next : graph[curr]) {
                if(prevEdgeColor != next.second && next.first != -1) {
                    q.push({ next.first, dist+1, next.second });
                    
                    // Update the value in the node to -1 to denote that the node has already been visited.
                    next.first = -1; 
                }
            }
            
        }
        
        return result;
    }
};