class Solution {
public:
    int check(vector<int>& rods, int i, int n, int balance, vector<vector<int>>& dp) {
        
        if(i >= n) {
            if(balance == 0) return 0;
            return INT_MIN;
        }
        
        if(dp[i][balance + 5000] != -1) return dp[i][balance + 5000];
        
        int skip = check(rods, i+1, n, balance, dp);
        int take = rods[i] + check(rods, i+1, n, balance + rods[i], dp);
        int give = rods[i] + check(rods, i+1, n, balance - rods[i], dp);
        
        return dp[i][balance + 5000] = max({ skip, take, give });
    }
    
    int tallestBillboard(vector<int>& rods) {
        
        int n = rods.size();
        
        vector<vector<int>> dp(n, vector<int>(10001, -1));
        return check(rods, 0, n, 0, dp) / 2;
    }
};