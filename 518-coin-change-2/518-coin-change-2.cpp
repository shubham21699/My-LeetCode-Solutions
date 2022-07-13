class Solution {
public:
    int ways(vector<int>& coins, int amount, int n, int count, vector<vector<int>>& dp) {
        
        if(amount == 0) return 1;
        if(amount < 0 || n < 0) return 0;
        if(dp[n][amount] != -1) return dp[n][amount];
        
        return dp[n][amount] = ways(coins, amount - coins[n], n, count+1, dp) + 
            ways(coins, amount, n-1, count, dp);
    }
    
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        if(amount == 0) return 1;
        
        vector<vector<int>> dp(n, vector<int>(2*amount, -1));
        sort(coins.begin(), coins.end());
        
        int ans = ways(coins, amount, n-1, 0, dp);
        return ans;
        
    }
};