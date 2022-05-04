class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        /* Sell_stock represents the max profit on day i if we don't have a stock and don't buy or have a
        stock and sell it.
        Keep_stock represents the max profit on day i if we buy a stock or have a stock and keep it.
        In iteration i:
            1. sellStock = maximum between:
                sellstock - if in iteration i-1 we sold the stock or had none and now we don't want to buy,
                or keepstock + prices[i] - fee if we have a stock and want to sell it.
            2. keepStock = maximum between:
                keepstock if in iteration i-1 we had a stock or bought one and now we are keeping it,
                or sellstock - prices[i] if we have no stock and want to buy one now.
        
        We return sell_stock because it's for sure better to sell the last stock than keep it.*/
        
        int n = prices.size();
        int sellStock = 0;
        int keepStock = -prices[0];
        
        for(int i=1 ; i<n ; i++) {
            sellStock = max(sellStock, keepStock + prices[i] - fee);
            keepStock = max(keepStock, sellStock - prices[i]);
        }
        
        return sellStock;
    }
};