class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        // BFS Approach :-
        
        // NoOfObstaclesWeCanRemove[i][j] == -1 means we haven't visited that block till now
        vector<vector<int>> NoOfObstaclesWeCanRemove(n, vector<int>(m, -1));
        queue<vector<int>> q;
        q.push({ 0, 0, k, 0 }); // { i, j, k, distance }
        
        while(!q.empty()) {
            
            auto v = q.front();
            q.pop();
            int i = v[0];
            int j = v[1];
            k = v[2];
            int dist = v[3];
            
            // Reached the Destination
            if(i == n-1 && j == m-1) return dist;
            
            // For Down
            if(i+1 < n && (NoOfObstaclesWeCanRemove[i+1][j] == -1 || NoOfObstaclesWeCanRemove[i+1][j] < k)) {
                if(grid[i+1][j] == 0) {
                    q.push({ i+1, j, k, dist+1 });
                    NoOfObstaclesWeCanRemove[i+1][j] = k;
                }
                if(grid[i+1][j] == 1 && k>0) {
                    q.push({ i+1, j, k-1, dist+1 });
                    NoOfObstaclesWeCanRemove[i+1][j] = k-1;
                }
            }
            
            // For Up
            if(i-1 >= 0 && (NoOfObstaclesWeCanRemove[i-1][j] == -1 || NoOfObstaclesWeCanRemove[i-1][j] < k)) {
                if(grid[i-1][j] == 0) {
                    q.push({ i-1, j, k, dist+1 });
                    NoOfObstaclesWeCanRemove[i-1][j] = k;
                }
                if(grid[i-1][j] == 1 && k>0) {
                    q.push({ i-1, j, k-1, dist+1 });
                    NoOfObstaclesWeCanRemove[i-1][j] = k-1;
                } 
            }
            
            // For Right
            if(j+1 < m && (NoOfObstaclesWeCanRemove[i][j+1] == -1 || NoOfObstaclesWeCanRemove[i][j+1] < k)) {
                if(grid[i][j+1] == 0) {
                    q.push({ i, j+1, k, dist+1 });
                    NoOfObstaclesWeCanRemove[i][j+1] = k;
                }
                if(grid[i][j+1] == 1 && k>0) {
                    q.push({ i, j+1, k-1, dist+1 });
                    NoOfObstaclesWeCanRemove[i][j+1] = k-1;
                }
            }
            
            // For Left
            if(j-1 >= 0 && (NoOfObstaclesWeCanRemove[i][j-1] == -1 || NoOfObstaclesWeCanRemove[i][j-1] < k)) {
                if(grid[i][j-1] == 0) {
                    q.push({ i, j-1, k, dist+1 });
                    NoOfObstaclesWeCanRemove[i][j-1] = k;
                }
                if(grid[i][j-1] == 1 && k>0) {
                    q.push({ i, j-1, k-1, dist+1 });
                    NoOfObstaclesWeCanRemove[i][j-1] = k-1;
                }
            }
            
        }
        
        return -1;
    }
};