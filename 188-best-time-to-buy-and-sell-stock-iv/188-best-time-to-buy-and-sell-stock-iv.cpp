class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        if(n <= 1) return 0;
        
        if(k >= n/2) {
            int profit = 0;
            
            for(int i=1 ; i<n ; i++) {
                profit += max(0, prices[i]-prices[i-1]);    
            }
            
            return profit;
        }
        
        vector<int> buys(k+1, INT_MIN);
        vector<int> sells(k+1, 0);
        
        for(int i=0 ; i<n ; i++) {
            for(int j=1 ; j<=k ; j++) {
                buys[j] = max(buys[j], sells[j-1] - prices[i]);
                sells[j] = max(sells[j], buys[j] + prices[i]);
            }
        }
        
        return sells[k];
        
    }
};