class Solution {
public:
    int insertions(string& s, int i, int j, vector<vector<int>>& dp) {
        
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == s[j]) return dp[i][j] = insertions(s, i+1, j-1, dp);
        
        return dp[i][j] = 1 + min(insertions(s, i, j-1, dp), insertions(s, i+1, j, dp));
    }
    
    int minInsertions(string s) {
        
        int n = s.length();
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return insertions(s, 0, n-1, dp);
    }
};