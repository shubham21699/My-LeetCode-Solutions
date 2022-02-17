class Solution {
public:
    bool isMatch(string s, string p) {
        
        int n = s.length();
        int m = p.length();
        
        vector<vector<bool> > dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        
        for(int j=1 ; j<=m ; j++) {
            // Only '*' can match with empty string 
            if(p[j-1] == '*') dp[0][j] = dp[0][j-1];
        }
        
        for(int i=1 ; i<=n ; i++) {
            for(int j=1 ; j<=m ; j++) {
                // Current characters are considered as match in two cases:
                // a) current character of pattern string is '?'
                // b) current character of both string 's' and pattern string matches
                if(p[j-1] == '?' || s[i-1] == p[j-1]) dp[i][j] = dp[i-1][j-1];
                
                // If current character of pattern string is '*', then there are two cases possible:
                // a) we ignore '*' and move to next character in pattern, i.e. '*' indicates empty sequence
                // b) '*' matches wit hith character in input
                else if(p[j-1] == '*') dp[i][j] = dp[i][j-1] || dp[i-1][j];
                
                // If characters doesn't match
                else dp[i][j] = false; 
            }
        }
        
        return dp[n][m];
    }
};