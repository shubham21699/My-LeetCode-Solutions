class Solution {
public:
    int maxCoins(vector<vector<int>>& piles, int i, int n, int k, vector<vector<int>>& dp) {
        
        if(k == 0 || i >= n) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        
        int val = 0;
        int ans = 0;
        
        for(int j=0 ; j<min(int(piles[i].size()), k) ; j++) {
            val += piles[i][j];
            ans = max({ ans, val + maxCoins(piles, i+1, n, k-(j+1), dp), maxCoins(piles, i+1, n, k, dp) });
        }
        
        return dp[i][k] = ans;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        int n = piles.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        
        return maxCoins(piles, 0, n, k, dp);
    }
};