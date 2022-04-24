class Solution {
    void neglectCornerIslands(vector<vector<int>>& grid, int i, int j, int n, int m) {
        
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] == 1) return;
        
        grid[i][j] = 1;
        neglectCornerIslands(grid, i+1, j, n, m);
        neglectCornerIslands(grid, i, j+1, n, m);
        neglectCornerIslands(grid, i-1, j, n, m);
        neglectCornerIslands(grid, i, j-1, n, m);
        
    }
    
    void includeThisIsland(vector<vector<int>>& grid, int i, int j, int n, int m) {
        
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] != 0) return;
        
        grid[i][j] = 2;
        includeThisIsland(grid, i+1, j, n, m);
        includeThisIsland(grid, i, j+1, n, m);
        includeThisIsland(grid, i-1, j, n, m);
        includeThisIsland(grid, i, j-1, n, m);
        
    }
    
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0 ; i<n ; i++) {
            if(grid[i][0] == 0) neglectCornerIslands(grid, i, 0, n, m);
            if(grid[i][m-1] == 0) neglectCornerIslands(grid, i, m-1, n, m);
        }
        for(int j=0 ; j<m ; j++) {
            if(grid[0][j] == 0) neglectCornerIslands(grid, 0, j, n, m);
            if(grid[n-1][j] == 0) neglectCornerIslands(grid, n-1, j, n, m);
        }
        
        int islands = 0;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                if(grid[i][j] == 0) {
                    includeThisIsland(grid, i, j, n, m);
                    islands++;
                }
            }
        }
        
        return islands;
    }
};