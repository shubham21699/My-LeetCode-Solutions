class Solution {
    long long sell(int m, int n, map<pair<int, int>, int>& mp, vector<vector<long long>>& dp) {
        
        if(m <= 0 || n <= 0) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        
        long long earn = mp.find({ m, n })!=mp.end() ? mp[{ m, n }] : 0;
        
        // For Horizontal Cuts:
        for(int i=1 ; i<m ; i++) earn = max(earn, sell(i, n, mp, dp) + sell(m-i, n, mp, dp));
        
        // For Vertical Cuts:
        for(int j=1 ; j<n ; j++) earn = max(earn, sell(m, j, mp, dp) + sell(m, n-j, mp, dp));
        
        return dp[m][n] = earn;
    }
    
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
                
        map<pair<int, int>, int> mp;
        
        for(int i=0 ; i<prices.size() ; i++) {
            mp[{ prices[i][0], prices[i][1] }] = prices[i][2];
        }
        
        vector<vector<long long>> dp(m+1, vector<long long>(n+1, -1));
        return sell(m, n, mp, dp);
    }
};