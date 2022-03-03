class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int current_buy = INT_MIN;
        int current_sell = 0;
        int prev_buy;
        int prev_sell = 0;
        
        for(int i=0 ; i<n ; i++) {
            prev_buy = current_buy;
            current_buy = max(prev_sell - prices[i], current_buy);
            prev_sell = current_sell;
            current_sell = max(prev_buy + prices[i], current_sell);
        }
        
        return current_sell;
    }
};