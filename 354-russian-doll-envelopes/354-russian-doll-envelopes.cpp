class Solution {
public:
    int russian(vector<vector<int>>& envelopes, int i, int n, int prev, vector<vector<int>>& dp) {
        
        if(i >= n) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1]; 
        
        int include = 0;
        if(prev == -1 || envelopes[i][0] > envelopes[prev][0] && envelopes[i][1] > envelopes[prev][1]) 
            include = 1 + russian(envelopes, i+1, n, i, dp);
        
        int exclude = 0 + russian(envelopes, i+1, n, prev, dp);
        return dp[i][prev+1] = max(include, exclude);
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        int n = envelopes.size();
        if(n == 1) return 1;
        
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        
        vector<int> dp;
        
        for(int i=0 ; i<n ; i++) {
            
            auto it = lower_bound(dp.begin(), dp.end(), envelopes[i][1]);
            if(it == dp.end()) dp.push_back(envelopes[i][1]);
            else *it = envelopes[i][1];
            
        }
        
        return dp.size();
        
        // // OR: Will give TLE
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return russian(envelopes, 0, n, -1, dp);
    }
};