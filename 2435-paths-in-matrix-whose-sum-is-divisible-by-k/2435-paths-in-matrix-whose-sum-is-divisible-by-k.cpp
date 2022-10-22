class Solution {
public:
    int mod = pow(10, 9) + 7;
    
    int paths(vector<vector<int>>& grid, int i, int j, int n, int m, int sum, int k, vector<vector<vector<int>>>& dp) {
        
        if(i >= n || j >= m) return 0;
        
        sum = (sum + grid[i][j]) % k;
        
        if(i == n-1 && j == m-1) {
            if(sum == 0) return 1;
            return 0;
        }
        if(dp[i][j][sum] != -1) return dp[i][j][sum];
        
        return dp[i][j][sum] = (paths(grid, i+1, j, n, m, sum, k, dp) + paths(grid, i, j+1, n, m, sum, k, dp)) % mod;
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k+1, -1)));
        return paths(grid, 0, 0, n, m, 0, k, dp);
    }
};