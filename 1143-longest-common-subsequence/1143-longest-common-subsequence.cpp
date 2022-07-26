class Solution {
public:
    int LCS(string& text1, string& text2, int i, int j, int n, int m, vector<vector<int>>& dp) {
        
        if(i == n || j == m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(text1[i] == text2[j]) return dp[i][j] = 1 + LCS(text1, text2, i+1, j+1, n, m, dp);

        return dp[i][j] = max(LCS(text1, text2, i+1, j, n, m, dp), LCS(text1, text2, i, j+1, n, m, dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.length();
        int m = text2.length();
        
        if(text1 == text2) return n;
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        return LCS(text1, text2, 0, 0, n, m, dp);
    }
};