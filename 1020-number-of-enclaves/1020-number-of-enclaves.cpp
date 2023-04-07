class Solution {
public:
    void countMoves(vector<vector<int>>& grid, int i, int j, int n, int m, int& count) {
        
        if(i<0 || j<0 || i>=n || j >=m || grid[i][j] == 0) return;
        
        count++;
        grid[i][j] = 0;
        countMoves(grid, i+1, j, n, m, count);
        countMoves(grid, i, j+1, n, m, count);
        countMoves(grid, i-1, j, n, m, count);
        countMoves(grid, i, j-1, n, m, count);
        
    }
    
    void neglectBoundaryLand(vector<vector<int>>& grid, int i, int j, int n, int m) {
        
        if(i<0 || j<0 || i>=n || j >=m || grid[i][j] == 0) return;
        
        grid[i][j] = 0;
        neglectBoundaryLand(grid, i+1, j, n, m);
        neglectBoundaryLand(grid, i, j+1, n, m);
        neglectBoundaryLand(grid, i-1, j, n, m);
        neglectBoundaryLand(grid, i, j-1, n, m);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0 ; i<n ; i++) {
            if(grid[i][0] == 1) neglectBoundaryLand(grid, i, 0, n, m);
            if(grid[i][m-1] == 1) neglectBoundaryLand(grid, i, m-1, n, m);
        }
        
         for(int j=0 ; j<m ; j++) {
            if(grid[0][j] == 1) neglectBoundaryLand(grid, 0, j, n, m);
            if(grid[n-1][j] == 1) neglectBoundaryLand(grid, n-1, j, n, m);
        }
        
        int count = 0;
        
        for(int i=1 ; i<n ; i++) {
            for(int j=1 ; j<m ; j++) {
                if(grid[i][j] == 1) countMoves(grid, i, j, n, m, count);
            }
        }
     
        return count;
    }
};