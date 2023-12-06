class Solution {
public:
    int totalMoney(int n) {
        
        vector<int> dp(n+1);
        int mondayAmt = 1;
        int money = 0;
        
        for(int i=1 ; i<=n ; i++) {
            if(i % 7 == 1) dp[i] = mondayAmt++;
            else dp[i] = dp[i-1] + 1;
            
            money += dp[i];
        }
        
        return money;
    }
};