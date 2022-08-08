class Solution {
public:
    int profit(vector<int>& prices, int i, int n, int buyOrSell, int noOfTransactionsLeft, vector<vector<vector<int>>>& dp) {
        
        if(noOfTransactionsLeft == 0) return 0;
        if(i >= n) return 0;
        if(dp[i][buyOrSell][noOfTransactionsLeft] != -1) return dp[i][buyOrSell][noOfTransactionsLeft];
        
        int ans = 0;
        
        if(buyOrSell == 0) // max of If we buy curr stock or not.
            ans = max(-prices[i] + profit(prices, i+1, n, 1, noOfTransactionsLeft, dp), profit(prices, i+1, n, 0, noOfTransactionsLeft, dp));
        else if(buyOrSell == 1) // max of If we sell curr stock or not.
            ans = max(prices[i] + profit(prices, i+1, n, 0, noOfTransactionsLeft-1, dp), profit(prices, i+1, n, 1, noOfTransactionsLeft, dp));
        
        
        return dp[i][buyOrSell][noOfTransactionsLeft] = ans;
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        if(n == 1) return 0;
        if(n == 2) return max(0, prices[1] - prices[0]);
        if(n == 3) return max({ prices[1]-prices[0], prices[2]-prices[1], prices[2]-prices[0], 0 });
        
        int noOfTransactionsLeft = 2;
        int buyOrSell = 2; // Here, 0 -> buy stock, 1 -> sell stock
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(buyOrSell+1, vector<int>(noOfTransactionsLeft+1, -1)));
        return profit(prices, 0, n, 0, noOfTransactionsLeft, dp);
    }
};