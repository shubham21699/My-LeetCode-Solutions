class Solution {
public:
    int lis(string& s, int k, int i, int n, char prev, vector<vector<int>>& dp) {
        
        if(i >= n) return 0;
        if(dp[i][prev] != -1) return dp[i][prev];
        
        int inc = 0;
        if(prev == '0' || abs(s[i] - prev) <= k) 
            inc = 1 + lis(s, k, i+1, n, s[i], dp);
        
        int exc = lis(s, k, i+1, n, prev, dp);
        
        return dp[i][prev] = max(inc, exc);
    }
    
    int longestIdealString(string s, int k) {
        
        int n = s.length();
        if(n == 1) return 1;
        
        vector<vector<int>> dp(n, vector<int>('z'+1, -1));
        
        return lis(s, k, 0, n, '0', dp);
    }
};