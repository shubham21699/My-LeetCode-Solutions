class Solution {
public:
    long long tapsToOpen(vector<vector<int>>& waterRange, int i, int n, vector<int>& dp) {
        
        if(i > n) return INT_MAX;
        if(waterRange[i][1] == n) return 1;
        if(dp[i] != -1) return dp[i];
        
        long long ans = INT_MAX;
        
        for(int j=i+1 ; j<=n ; j++) {
            if(waterRange[j][0] > waterRange[i][1]) break; 
            ans = min(ans, 1 + tapsToOpen(waterRange, j, n, dp));
        }
        
        return dp[i] = ans;
    }
    
    int minTaps(int n, vector<int>& ranges) {
        
        vector<vector<int>> waterRange;
        
        for(int i=0 ; i<=n ; i++) {
            // Get the water range from 0 to n
            waterRange.push_back({ max(0, i-ranges[i]), min(i+ranges[i], n) });
            if(waterRange.back()[0] == 0 && waterRange.back()[1] == n) return 1; 
        }
        
        sort(waterRange.begin(), waterRange.end());
        
        vector<int> dp(n+1, -1);
        long long ans = INT_MAX;
        
        for(int i=0 ; i<=n ; i++) {
            if(waterRange[i][0] == 0) ans = min(ans, tapsToOpen(waterRange, i, n, dp));
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};