class Solution {
public:
    int mod = pow(10, 9) + 7;
    
    int peopleAwareOfSecret(int n, int delay, int forget) {
        
        int result = 0;
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=1 ; i<=delay ; i++) dp[i] = 1;
        
        for(int i=1+delay ; i<=n ; i++) {
            for(int j=delay ; j<forget ; j++) { // Tells the secret from delay till he forget.
                if(i-j <= 0) break;
                dp[i] += dp[i-j] % mod;
                dp[i] %= mod;
            }
            dp[i]++;
            dp[i] %= mod;
            
            if(i-forget >= 1) dp[i]--; // Because he forgetsd the secret.
        }
        
        return dp[n];
    }
};