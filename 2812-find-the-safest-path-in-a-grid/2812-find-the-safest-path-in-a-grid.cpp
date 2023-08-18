class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return 0; // If thief exist at either start or end position.
        if(n == 1) return 0; // If size is 1 and no thief
        if(n == 2) {
            if(grid[0][1] == 1 && grid[1][0] == 1) return 0;
            if(grid[0][1] == 1 || grid[1][0] == 1) return 1;
            return 0; // If no thief
        }
        
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        queue<pair<int, int>> q;
        
        // Insert all the thieves in the queue
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(grid[i][j] == 1) q.push({ i, j });
            }
        }
        
        // Find the safeness factor of each cell from all thieves
        while(!q.empty()) {
            
            auto p = q.front();
            q.pop();
            
            for(int k=0 ; k<4 ; k++) {
                int x = p.first + dir[k][0];
                int y = p.second + dir[k][1];
                
                if(x>=0 && y>=0 && x<n && y<n && grid[x][y] == 0) {
                    q.push({ x, y });
                    grid[x][y] = grid[p.first][p.second] + 1;
                }
            }
            
        }
        
        priority_queue<vector<int>> safeFactor;
        safeFactor.push({ grid[0][0], 0, 0 });
        
        // Get the maximum of minimum safeness factor incounter in the traversal from start to end position
        while(!safeFactor.empty()) {
            
            auto v = safeFactor.top();
            safeFactor.pop();
            
            if(v[1] == n-1 && v[2] == n-1) break;
            
            for(int k=0 ; k<4 ; k++) {
                int x = v[1] + dir[k][0];
                int y = v[2] + dir[k][1];
                
                if(x>=0 && y>=0 && x<n && y<n && grid[x][y] > 0) {
                    safeFactor.push({ min(v[0], grid[x][y]), x, y });
                    grid[x][y] = -1;
                }
            }
             
        }
        
        return safeFactor.top()[0] - 1;
    }
};