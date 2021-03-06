class Solution {
    int find(string& s, int i, int j, vector<vector<int> >& dp) {
        
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != 0) return dp[i][j];
        
        if(s[i] == s[j]) dp[i][j] = find(s, i+1, j-1, dp) + 2;
        else dp[i][j] = max(find(s, i+1, j, dp), find(s, i, j-1, dp));
        
        return dp[i][j];
    }
    
public:
    int longestPalindromeSubseq(string s) {
        
        int n = s.length();
        
        if(n == 1) return 1;
        if(n == 2) {
            if(s[0] == s[1]) return 2;
            return 1;
        }
        
        vector<vector<int> > dp(n, vector<int>(n, 0));
        return find(s, 0, n-1, dp);
    }
};