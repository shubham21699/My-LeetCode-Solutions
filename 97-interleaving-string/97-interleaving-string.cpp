class Solution {
public:
    bool check(string s1, string s2, string s3, int i, int j, int k, int n, int m, int r, vector<vector<int>>& dp) {
        
        if(i >= n && j >= m) return true;
        if(dp[i][j] != -1) return dp[i][j];
        bool flag = false;
        
        if(i < n && s1[i] == s3[k]) flag |= check(s1, s2, s3, i+1, j, k+1, n, m, r, dp);
        if(j < m && s2[j] == s3[k]) flag |= check(s1, s2, s3, i, j+1, k+1, n, m, r, dp);
        
        return dp[i][j] = flag;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        
        int n = s1.length();
        int m = s2.length();
        int r = s3.length();
        
        if(n+m != r) return false;
        if(n == 0 && m == 0) return true;
        if(n == 0) return s2 == s3;
        if(m == 0) return s1 == s3;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        return check(s1, s2, s3, 0, 0, 0, n, m, r, dp);
    }
};