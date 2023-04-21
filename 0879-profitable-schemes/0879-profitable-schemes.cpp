class Solution {
public:
    int mod = pow(10, 9) + 7;
    
    int scheme(vector<int>& group, vector<int>& profit, int i, int n, int m, int minProfit, vector<vector<vector<int>>>& dp) {
        
        if(n < 0) return 0;
        if(i == m) {
            if(minProfit > 0) return 0;
            return 1;
        }
        if(minProfit < 0) minProfit = 0;
        
        if(dp[i][n][minProfit] != -1) return dp[i][n][minProfit];
        
        int pick = scheme(group, profit, i+1, n-group[i], m, minProfit-profit[i], dp);
        int notPick = scheme(group, profit, i+1, n, m, minProfit, dp);
        
        return dp[i][n][minProfit] = (pick + notPick) % mod;
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        
        int m = group.size();
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n+1, vector<int>(minProfit+1, -1)));
        return scheme(group, profit, 0, n, m, minProfit, dp);
    }
};