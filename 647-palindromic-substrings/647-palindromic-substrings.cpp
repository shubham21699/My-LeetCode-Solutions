class Solution {
    int calc(string s, int i, int j, vector<vector<int> >& dp) {
        if(i >= j) return dp[i][j] = 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] != s[j]) return dp[i][j] = 0;
        
        return dp[i][j] = calc(s, i+1, j-1, dp);
    }
    
public:
    int countSubstrings(string s) {
        
        int n = s.length();
        if(n == 1) return 1;
        if(n == 2) {
            if(s[0] == s[1]) return 3;
            return 2;
        }
        
        vector<vector<int> > dp(n, vector<int>(n, -1));
        int count = 0;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=i ; j<n ; j++) {
                count += calc(s, i, j, dp);
            }
        }
        
        return count;
    }
};