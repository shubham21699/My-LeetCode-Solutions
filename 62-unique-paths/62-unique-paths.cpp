class Solution {
    int find(int row, int col, int m, int n, vector<vector<int> >& dp) {
        
        if(row >= m || col >= n) return 0;
        if(row == m-1 && col == n-1) return 1;
        
        if(dp[row][col] != 0) return dp[row][col];
        
        dp[row][col] = find(row+1, col, m, n, dp) + find(row, col+1, m, n, dp);
        return dp[row][col];
    }
    
public:
    int uniquePaths(int m, int n) {
        
        if(m == 1 && n == 1) return 1;
        
        vector<vector<int> > dp(m, vector<int>(n, 0));
        return find(0, 0, m, n, dp);
    }
};