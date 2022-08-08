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

    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        if(n == 1 || k == 0) return 0;
        if(n == 2) return max(0, prices[1] - prices[0]);
        
        if(k == 1) {
            int profit = 0;
            int min_so_far = prices[0];
            
            for(int i=1 ; i<n ; i++) {
                profit = max(profit, prices[i]-min_so_far);
                min_so_far = min(min_so_far, prices[i]);
            }
            
            return profit;
        }
        
        if(k >= n/2) {
            int profit = 0;
            
            for(int i=1 ; i<n ; i++) {
                profit += max(0, prices[i]-prices[i-1]);
            }
            
            return profit;
        }
        
        int noOfTransactionsLeft = k;
        int buyOrSell = 2; // Here, 0 -> buy stock, 1 -> sell stock
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(buyOrSell+1, vector<int>(noOfTransactionsLeft+1, -1)));
        return profit(prices, 0, n, 0, noOfTransactionsLeft, dp);
        
//         // OR:
//         vector<int> buys(k+1, INT_MIN);
//         vector<int> sells(k+1, 0);
        
//         for(int i=0 ; i<n ; i++) {
//             for(int j=1 ; j<=k ; j++) {
//                 buys[j] = max(buys[j], sells[j-1] - prices[i]);
//                 sells[j] = max(sells[j], buys[j] + prices[i]);
//             }
//         }
        
//         return sells[k];
    }
};