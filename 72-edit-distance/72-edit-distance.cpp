class Solution {
     int find(string word1, string word2, int n, int m, vector<vector<int> >& dp) {
        
        if(n == 0) return m;
        if(m == 0) return n;
        
        if(dp[n][m] != 0) return dp[n][m];
        
        if(word1[n-1] == word2[m-1]) dp[n][m] = find(word1, word2, n-1, m-1, dp);
        else {
            dp[n][m] = 1 + min({ find(word1, word2, n-1, m, dp), find(word1, word2, n, m-1, dp),                                        find(word1, word2, n-1, m-1, dp) });
        }
        
        return dp[n][m];
    }
    
public:
    int minDistance(string word1, string word2) {
        
        if(word1 == word2) return 0;
        
        int n = word1.length();
        int m = word2.length();
        vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
        
/////////////////////// OR /////////////////////////////         
        // return find(word1, word2, n, m, dp);
        
        for(int i=0 ; i<=n ; i++) dp[i][0] = i;
        for(int j=0 ; j<=m ; j++) dp[0][j] = j;
        
        for(int i=1 ; i<=n ; i++) {
            for(int j=1 ; j<=m ; j++) {
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else {
                    dp[i][j] = 1 + min({ dp[i-1][j], dp[i][j-1], dp[i-1][j-1] });
                }
            }
        }
        
        return dp[n][m];
        
    }
};