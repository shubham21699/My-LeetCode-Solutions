class Solution {
public:
    int deleteString(string s) {
        
        int n = s.length();
        vector<vector<int>> lcs(n+1, vector<int>(n+1, 0));
        vector<int> dp(n, 1);
        
        for(int i=n-1 ; i>=0 ; i--) {
            for(int j=i+1 ; j<n ; j++) {
                if(s[i] == s[j]) {
                    lcs[i][j] = lcs[i+1][j+1] + 1;
                }
                
                // If lcs[i][j] >= j - i, s.substring(i, j) == s.substring(j, j + j - i)
                // this means we can delete the prefix s.substring(i, j) from s.substring(i), 
                // and it changes to s.substring(j). And we update dp[i] = max(dp[i], dp[j] + 1)                
                if(lcs[i][j] >= j-i) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        return dp[0];
    }
};