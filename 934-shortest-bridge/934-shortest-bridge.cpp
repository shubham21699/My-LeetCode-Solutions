class Solution {
    void dfs(vector<vector<int>>& grid, int i, int j, int n, int m, int islandNo) {
        
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] != 1) return;
        
        grid[i][j] = islandNo;
        
        dfs(grid, i+1, j, n, m, islandNo);
        dfs(grid, i, j+1, n, m, islandNo);
        dfs(grid, i-1, j, n, m, islandNo);
        dfs(grid, i, j-1, n, m, islandNo);
        
    }
    
public:
    int shortestBridge(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        bool flag = true;
        
        // Giving one island different number.
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, i , j, n, m, 2);
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        
        // Storing coordinates of both islands border points that are connected with water.
        set<pair<int, int>> island1, island2;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                if(grid[i][j] == 1) {
                    if((i+1<n && grid[i+1][j] == 0) || (j+1<m && grid[i][j+1] == 0) || (i-1>=0 && grid[i-1][j] == 0) || (j-1>=0 && grid[i][j-1] == 0)) island1.insert({ i, j });
                }
                       
                if(grid[i][j] == 2) {
                    if((i+1<n && grid[i+1][j] == 0) || (j+1<m && grid[i][j+1] == 0) || (i-1>=0 && grid[i-1][j] == 0) || (j-1>=0 && grid[i][j-1] == 0)) island2.insert({ i, j });
                }
            }
        }
        
        int bridgeLen = INT_MAX;
        
        // Calculating distance between all the border points of islands and store minimum of them.
        for(auto it1 : island1) {
            for(auto it2 : island2) {
                int x = abs(it1.first - it2.first);
                int y = abs(it1.second - it2.second);
                bridgeLen = min(bridgeLen, x + y - 1);
            }
        }              
         
        return bridgeLen;               
    }
};