class Solution {
public:
    int profit(vector<int>& prices, int i, int n, int buyOrSale, vector<vector<int>>& dp) {
        
        if(i >= n) return 0;
        if(dp[i][buyOrSale] != -1) return dp[i][buyOrSale];
        
        int ans = 0;
        
        if(buyOrSale == 0) {
            ans = max(-prices[i] + profit(prices, i+1, n, 1, dp), profit(prices, i+1, n, 0, dp));
        }
        else if(buyOrSale == 1) {
            ans = max(prices[i] + profit(prices, i+2, n, 0, dp), profit(prices, i+1, n, 1, dp));
        }
        
        return dp[i][buyOrSale] = ans;
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        if(n == 1) return 0;
        if(n == 2) return max(0, prices[1] - prices[0]);
        
        int buyOrSale = 2; // Here, 0 -> buy stock and 1 -> sell stock
        vector<vector<int>> dp(n, vector<int>(buyOrSale, -1));
        return profit(prices, 0, n, 0, dp);
        
//         // OR:
//         int n = prices.size();
//         int current_buy = INT_MIN;
//         int current_sell = 0;
//         int prev_buy;
//         int prev_sell = 0;
        
//         for(int i=0 ; i<n ; i++) {
//             prev_buy = current_buy;
//             current_buy = max(prev_sell - prices[i], current_buy);
//             prev_sell = current_sell;
//             current_sell = max(prev_buy + prices[i], current_sell);
//         }
        
//         return current_sell;
    }
};