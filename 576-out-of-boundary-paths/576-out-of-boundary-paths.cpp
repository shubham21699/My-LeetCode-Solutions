class Solution {
    int mod = pow(10, 9) + 7;
    
    long long int moves(int maxMove, int i, int j, int m, int n, vector<vector<vector<long long int>>>& dp) {
        
        if(i < 0 || j < 0 || i >= m || j >= n) return 1;
        if(maxMove == 0) return 0;
        if(dp[i][j][maxMove] != -1) return dp[i][j][maxMove] % mod;
        
        return dp[i][j][maxMove] = (moves(maxMove-1, i+1, j, m, n, dp) % mod + 
                                    moves(maxMove-1, i, j+1, m, n, dp) % mod + 
                                    moves(maxMove-1, i-1, j, m, n, dp) % mod + 
                                    moves(maxMove-1, i, j-1, m, n, dp) % mod) % mod;
    }
    
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        if(maxMove == 0) return 0;
        if(m == 1 && n == 1) return 4;
        
        vector<vector<vector<long long int>>> dp(m, vector<vector<long long int>>(n, vector<long long int>(maxMove+1, -1)));
        
        return moves(maxMove, startRow, startColumn, m, n, dp) % mod;
    }
};