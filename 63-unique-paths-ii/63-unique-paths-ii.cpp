class Solution {
    int count(vector<vector<int>>& obstacleGrid, int i, int j, int n, int m, vector<vector<int>>& dp) {
        
        if(i<0 || j<0 || i>=n || j>=m || obstacleGrid[i][j] == 1) return 0;
        if(i == n-1 && j == m-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = count(obstacleGrid, i+1, j, n, m, dp) + count(obstacleGrid, i, j+1, n, m, dp);
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        if(obstacleGrid[n-1][m-1] == 1 || obstacleGrid[0][0] == 1) return 0;
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return count(obstacleGrid, 0, 0, n, m, dp);
    }
};