class Solution {
    int find(vector<int>& coins, int amount, int index, vector<vector<int> >& dp) {
        
        if(amount == 0) return 0;
        if(index < 0) return INT_MAX-1;
        if(dp[amount][index] != -1) return dp[amount][index];
        
        if(coins[index] <= amount) dp[amount][index] = min(1 + find(coins, amount-coins[index], index, dp), 0 + find(coins, amount, index-1, dp));
        else dp[amount][index] = 0 + find(coins, amount, index-1, dp);
        
        return dp[amount][index];
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        
        if(amount == 0) return 0;
        if(n == 1 && coins[0] == amount) return 1;
        if(n == 1 && coins[0] > amount) return -1;
        
        sort(coins.begin(), coins.end());
        vector<vector<int> > dp(amount+1, vector<int>(n+1, -1));
        
        int result = find(coins, amount, n-1, dp);
        return result == INT_MAX-1 ? -1 : result;
    }
};