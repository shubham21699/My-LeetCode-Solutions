class Solution {
public:
    bool isMatch(string s, string p) {
        
        int n = s.length();
        int m = p.length();
        
        if(s == p) return true;
        
        vector<vector<bool> > dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        
//       We define dp[i][j] to be true if s[0..i) matches p[0..j) and false otherwise.
//       The state equations will be:

//       dp[i][j] = dp[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
//       dp[i][j] = dp[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 time;
//       dp[i][j] = dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 time.
        
        for(int i=0 ; i<=n ; i++) {
            for(int j=1 ; j<=m ; j++) {
                if(p[j-1] == '*') {
                    dp[i][j] = dp[i][j-2] || (i && dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
                }
                else dp[i][j] = i && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
            }
        }
        
        return dp[n][m];
    }
};