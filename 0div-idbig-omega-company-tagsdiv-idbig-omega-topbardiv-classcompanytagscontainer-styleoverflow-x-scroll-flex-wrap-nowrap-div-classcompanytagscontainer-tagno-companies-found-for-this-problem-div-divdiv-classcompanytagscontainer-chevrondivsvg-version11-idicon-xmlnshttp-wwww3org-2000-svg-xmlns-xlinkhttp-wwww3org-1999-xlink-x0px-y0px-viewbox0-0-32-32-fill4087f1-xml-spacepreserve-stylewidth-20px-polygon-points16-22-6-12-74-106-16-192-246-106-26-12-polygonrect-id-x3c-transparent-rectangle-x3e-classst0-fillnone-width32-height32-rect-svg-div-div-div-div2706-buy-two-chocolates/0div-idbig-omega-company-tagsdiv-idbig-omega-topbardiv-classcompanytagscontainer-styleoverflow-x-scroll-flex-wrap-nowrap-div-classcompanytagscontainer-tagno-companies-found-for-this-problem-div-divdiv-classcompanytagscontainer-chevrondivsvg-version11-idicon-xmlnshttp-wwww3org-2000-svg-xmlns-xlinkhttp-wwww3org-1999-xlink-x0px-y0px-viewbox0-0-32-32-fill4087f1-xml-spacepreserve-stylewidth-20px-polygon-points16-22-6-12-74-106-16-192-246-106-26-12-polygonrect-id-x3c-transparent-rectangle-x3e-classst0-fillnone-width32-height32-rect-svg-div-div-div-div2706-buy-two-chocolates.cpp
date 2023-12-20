class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        
        int n = prices.size();
        int minPrice1 = INT_MAX, minPrice2 = INT_MAX;
        
        for(int i=0 ; i<n ; i++) {
            if(minPrice1 > prices[i]) {
                minPrice2 = minPrice1;
                minPrice1 = prices[i];
            }
            else if(minPrice2 > prices[i]) minPrice2 = prices[i];
        }
        
        return money >= (minPrice1 + minPrice2) ? money - (minPrice1 + minPrice2) : money; 
    }
};