class Solution {
    
    int minPathSum(vector<vector<int>>& matrix, int i, int j, int n, int sum, vector<vector<int>>& dp) {
        
        if(i < 0 || j < 0 || i >= n || j >= n) return INT_MAX;
        if(i == n-1) return matrix[i][j];
        
        if(dp[i][j] != INT_MAX) return dp[i][j];
        
        return dp[i][j] = matrix[i][j] + min({ minPathSum(matrix, i+1, j-1, n, sum + matrix[i][j], dp), 
                    minPathSum(matrix, i+1, j, n, sum + matrix[i][j], dp), 
                    minPathSum(matrix, i+1, j+1, n, sum + matrix[i][j], dp) });
        
    }
    
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        if(n == 1) return matrix[0][0];
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));
        int result  = INT_MAX;
        
        for(int j=0 ; j<n ; j++) {
            result = min(result, minPathSum(matrix, 0, j, n, 0, dp));
        }
        
        return result;
    }
};