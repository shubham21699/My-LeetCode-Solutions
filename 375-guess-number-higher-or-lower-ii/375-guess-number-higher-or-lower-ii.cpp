class Solution {
public:
    int solve(int l, int r, vector<vector<int>>& dp) {
        
        if(l >= r) return 0;
        if(dp[l][r] != 0) return dp[l][r];
        
        // Binary Search Approach -
        int ans = INT_MAX;
        
        for(int i=r ; i>=(l+r)/2 ; i--) {
            
            int left = solve(l, i - 1, dp);
            int right = solve(i + 1, r, dp);
            
            int ansForCurrVal = i + max(left, right);
            
            if(ansForCurrVal > ans) break;
            ans = ansForCurrVal;
        }
        
        return dp[l][r] = ans;
    }
    
    int getMoneyAmount(int n) {
        
        if(n == 1) return 0;
        if(n == 2) return 1;
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        return solve(1, n, dp);
        
//         // OR:
//         for(int len=2 ; len<=n ; len++) {
//             for(int begin=0 ; begin<=n-len ; begin++) {
//                 int end = begin + len;
                
//                 for(int i=begin ; i<end ; i++) {
                    
//                     int numPicked = i+1;
                    
//                     if(i == begin) dp[begin][end] = numPicked + dp[begin + 1][end];
//                     else dp[begin][end] = min(dp[begin][end], max(dp[begin][i], dp[i+1][end]) + numPicked);
                    
//                 }
                
//             }
//         }
        
//         return dp[0][n];
    }
};