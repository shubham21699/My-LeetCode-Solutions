class Solution {
    int find(vector<vector<int> >& matrix, vector<vector<int> >& dp, int i, int j, int n, int m, int prev_value) {
        
        if(i<0 || j<0 || i>=n || j>=m || matrix[i][j] <= prev_value) return 0;
        if(dp[i][j] != 0) return dp[i][j];
        
        dp[i][j] = 1 + max({ find(matrix, dp, i-1, j, n, m, matrix[i][j]), find(matrix, dp, i, j-1, n, m, matrix[i][j]), find(matrix, dp, i+1, j, n, m, matrix[i][j]), find(matrix, dp, i, j+1, n, m, matrix[i][j]) });
        
        return dp[i][j];
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        if(n == 1 && m == 1) return 1;
        
        vector<vector<int> > dp(n, vector<int>(m, 0));
        int result = 0;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                result = max(result, find(matrix, dp, i, j, n, m, -1));
            }
        }
        
        return result;
    }
};