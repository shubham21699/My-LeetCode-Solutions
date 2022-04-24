class Solution {
    void dfs(vector<vector<int>>& newGrid, vector<vector<bool>>& visited, int i, int j, int n, int m) {
        
        if(i<0 || j<0 || i>=n || j>=m || newGrid[i][j] == 1 || visited[i][j]) return;
        
        visited[i][j] = true;
        newGrid[i][j] = 1;
        
        dfs(newGrid, visited, i+1, j, n, m);
        dfs(newGrid, visited, i, j+1, n, m);
        dfs(newGrid, visited, i-1, j, n, m);
        dfs(newGrid, visited, i, j-1, n, m);
        
    }
    
public:
    int regionsBySlashes(vector<string>& grid) {
        
        int n = grid.size()*3;
        int m = grid[0].size()*3;
        
        vector<vector<int>> newGrid(n, vector<int>(m, 0));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for(int i=0 ; i<grid.size() ; i++) {
            for(int j=0 ; j<grid[0].size() ; j++) {
                if(grid[i][j] == '/') {
                    newGrid[i*3][j*3 + 2] = 1;
                    newGrid[i*3 + 1][j*3 + 1] = 1;
                    newGrid[i*3 + 2][j*3] = 1;
                }
                else if(grid[i][j] == '\\') {
                    newGrid[i*3][j*3] = 1;
                    newGrid[i*3 + 1][j*3 + 1] = 1;
                    newGrid[i*3 + 2][j*3 + 2] = 1;
                }
            }
        }
        
        int regions = 0;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                
                if(!visited[i][j] && newGrid[i][j] == 0) {
                    dfs(newGrid, visited, i, j, n, m);
                    regions++;
                }
                
            }
        }
        
        return regions;
    }
};