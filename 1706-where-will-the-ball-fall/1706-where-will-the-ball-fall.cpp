class Solution {
    bool check(vector<vector<int>>& grid, int i, int j, int m, int n, int& col) {
        
        if(i >= m) {
            col = j;
            return true;
        }
        if(i<0 || j<0 || j>=n) return false;
        
        if(grid[i][j] == 1 && (j+1 == n || grid[i][j+1] == -1)) return false;
        if(grid[i][j] == -1 && (j-1 < 0 || grid[i][j-1] == 1)) return false;
        
        if(grid[i][j] == 1) return check(grid, i+1, j+1, m, n, col);
        return check(grid, i+1, j-1, m, n, col); // If grid[i][j] == -1
        
    }
    
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<int> result(n, -1);
        
        if(n == 1) return result;
        
        for(int j=0 ; j<n ; j++) {
            int colFromWhichBallFallsOut = 0;
            
            // DFS:
            if(check(grid, 0, j, m, n, colFromWhichBallFallsOut)) 
                result[j] = colFromWhichBallFallsOut;
        }
        
        return result;
    }
};