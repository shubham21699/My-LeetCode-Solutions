class Solution {
public:
    int mod = pow(10, 9) + 7;
    
    int find(vector<vector<int> >& matrix, vector<vector<int> >& dp, int i, int j, int n, int m, int prev_value) {
        
        if(i<0 || j<0 || i>=n || j>=m || matrix[i][j] <= prev_value) return 0;
        if(dp[i][j] != 0) return dp[i][j] % mod;
        
        dp[i][j] = ( 1 + find(matrix, dp, i-1, j, n, m, matrix[i][j]) + 
                    find(matrix, dp, i, j-1, n, m, matrix[i][j]) + 
                    find(matrix, dp, i+1, j, n, m, matrix[i][j]) + 
                    find(matrix, dp, i, j+1, n, m, matrix[i][j]) ) % mod;
        
        return dp[i][j] % mod;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(n == 1 && m == 1) return 1;
        
        vector<vector<int> > dp(n, vector<int>(m, 0));
        int result = 0;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                result += find(grid, dp, i, j, n, m, -1);
                result %= mod;
            }
        }
        
        return result;
        
    }
};