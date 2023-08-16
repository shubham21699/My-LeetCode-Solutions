class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int n, int m, int& perimeter) {
        
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] == 0 || grid[i][j] == -1) return;
        
        if((i-1<0) || (grid[i-1][j] == 0)) perimeter++;
        if((j-1<0) || (grid[i][j-1] == 0)) perimeter++;
        if((i+1==n) || (grid[i+1][j] == 0)) perimeter++;
        if((j+1==m) || (grid[i][j+1] == 0)) perimeter++;
        
        grid[i][j] = -1;
        
        dfs(grid, i+1, j, n, m, perimeter);
        dfs(grid, i, j+1, n, m, perimeter);
        dfs(grid, i-1, j, n, m, perimeter);
        dfs(grid, i, j-1, n, m, perimeter);
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int perimeter = 0;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, i, j, n, m, perimeter);
                    break;
                }
            }
        }
        
        return perimeter;
    }
};