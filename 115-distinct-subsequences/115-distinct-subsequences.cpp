class Solution {
public:
    int find(string& s, string& t, int i, int j, int n, int m, vector<vector<int>>& dp) {
        
        if(j == m) return 1;
        if(i >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == t[j]) return dp[i][j] = find(s, t, i+1, j+1, n, m, dp) + find(s, t, i+1, j, n, m, dp);
        
        return dp[i][j] = find(s, t, i+1, j, n, m, dp);
    }
    
    int numDistinct(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        
        if(s == t) return 1;
        if(n == m) return 0;
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return find(s, t, 0, 0, n, m, dp);
    }
};