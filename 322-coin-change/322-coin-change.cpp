class Solution {
    int find(vector<int>& coins, int amount, int index, vector<vector<int> >& dp) {
        
        if(amount == 0) return 0;
        if(index < 0) return INT_MAX;
        if(dp[amount][index] != -1) return dp[amount][index];
        
        if(coins[index] <= amount) dp[amount][index] = min(1 + find(coins, amount-coins[index], index, dp), 0 + find(coins, amount, index-1, dp));
        else dp[amount][index] = 0 + find(coins, amount, index-1, dp);
        
        return dp[amount][index];
    }
    
public:
    int dp[10000 + 1][12 + 1];
    
    int memoization(vector<int>& wt, int w, int n)
    {
        if (n == 0 || w == 0)
            return (w == 0) ? 0 : INT_MAX - 1;
        
        if (dp[w][n] != -1)
            return dp[w][n];
			
        if (wt[n - 1] > w) 
            return dp[w][n] = 0 + memoization(wt, w - 0, n - 1);
        else 
            return dp[w][n] = min(0 + memoization(wt, w - 0, n - 1), 1 + memoization(wt, w - wt[n - 1], n));
    }
    
    int coinChange(vector<int>& coins, int amount) 
    {
        memset(dp, -1, sizeof(dp));
        int minCoins = memoization(coins, amount, coins.size());
        return minCoins == INT_MAX - 1 ? -1 : minCoins;    
    }
    
//     int coinChange(vector<int>& coins, int amount) {
        
//         int n = coins.size();
        
//         if(amount == 0) return 0;
//         if(n == 1 && coins[0] == amount) return 1;
//         if(n == 1 && coins[0] > amount) return -1;
        
//         sort(coins.begin(), coins.end());
//         vector<vector<int> > dp(10000+1, vector<int>(12+1, -1));
        
//         int result = find(coins, amount, n-1, dp);
//         return result == INT_MAX ? -1 : result;
//     }
};