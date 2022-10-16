class Solution {
public:
    int difficulty(vector<int>& jobDifficulty, int ind, int n, int d, vector<vector<int>>& dp) {
        
        if((d == 0 && ind < n) || (d > 0 && ind >= n)) return INT_MAX;
        if(d == 0) return 0;
        if(dp[ind][d] != -1) return dp[ind][d];
        
        int maxDiff = 0;
        long long ans = INT_MAX;
        
        for(int i=ind ; i<n ; i++) {
            maxDiff = max(maxDiff, jobDifficulty[i]);
            ans = min(ans, (long long) maxDiff + difficulty(jobDifficulty, i+1, n, d-1, dp));
        }
        
        return dp[ind][d] = ans;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        int n = jobDifficulty.size();
        if(n < d) return -1;
        if(n == d) return accumulate(jobDifficulty.begin(), jobDifficulty.end(), 0);
        if(d == 1) return *max_element(jobDifficulty.begin(), jobDifficulty.end());
        
        vector<vector<int>> dp(n, vector<int>(d+1, -1));
        return difficulty(jobDifficulty, 0, n, d, dp);
    }
};