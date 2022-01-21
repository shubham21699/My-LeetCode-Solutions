class Solution {
    int calc(int n, vector<int>& dp) {
        
        if(n <= 3) return n;
        if(dp[n] != 0) return dp[n];
        
        return dp[n] = calc(n-1, dp) + calc(n-2, dp);
    }
    
public:
    int climbStairs(int n) {
        
        if(n <= 3) return n;
        vector<int> dp(n+1, 0);
        
        return calc(n, dp);
    }
};