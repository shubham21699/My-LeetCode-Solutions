class Solution {
    int find(vector<int>& coins, int amount, int index, vector<vector<int> >& dp) {
        
        if(amount == 0) return 0;
        if(index < 0) return INT_MAX-1;
        if(dp[amount][index] != -1) return dp[amount][index];
        
        if(coins[index] <= amount) dp[amount][index] = min(1 + find(coins, amount-coins[index], index, dp), find(coins, amount, index-1, dp));
        else dp[amount][index] = find(coins, amount, index-1, dp);
        
        return dp[amount][index];
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        
        if(amount == 0) return 0;
        if(n == 1 && coins[0] == amount) return 1;
        if(n == 1 && coins[0] > amount) return -1;
        
        vector<int> dp(amount+1, INT_MAX-1);
        dp[0] = 0;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=coins[i] ; j<=amount ; j++) {
                dp[j] = min(dp[j], 1 + dp[j-coins[i]]);
            }
        }
        
        return dp[amount] == INT_MAX-1 ? -1 : dp[amount];
        
//////////////////// OR: ///////////////////////////
//         vector<vector<int> > dp(amount+1, vector<int>(n+1, -1));
        
//         int result = find(coins, amount, n-1, dp);
//         return result == INT_MAX-1 ? -1 : result;
    }
};