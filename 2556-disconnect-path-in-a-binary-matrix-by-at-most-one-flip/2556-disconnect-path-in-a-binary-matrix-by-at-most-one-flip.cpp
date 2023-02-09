class Solution {
public: 
    bool dfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
        
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) return false;
        if(i == n-1 && j == m-1) return true;
        
        grid[i][j] = 0;
        return dfs(grid, i+1, j, n, m) || dfs(grid, i, j+1, n, m);
    }
    
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        if(n == 1 && m == 1) return false;
        if(n == 1) return m > 2 ? true : false;
        if(m == 1) return n > 2 ? true : false;
        if(grid[n-2][m-1] == 0 || grid[n-1][m-2] == 0) return true;
        if(grid[0][1] == 0 || grid[1][0] == 0) return true;
        
        // 1st run from 0,0 and changed all 1 to 0 in the paths.
        // Also if not reached to end meabs already disconnected.
        if(dfs(grid, 0, 0, n, m) == false) return true;

        // Again run dfs from 0,0 coordinates and if reached to end means not possible to disconnect
        grid[0][0] = 1;
        if(dfs(grid, 0, 0, n, m) == false) return true;
        
        return false;
    }
};