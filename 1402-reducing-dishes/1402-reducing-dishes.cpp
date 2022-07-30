class Solution {
public:
    int count(vector<int>& satisfaction, int i, int n, int time, vector<vector<int>>& dp) {
        
        if(i >= n) return 0;
        if(dp[i][time] != -1) return dp[i][time];
        
        return dp[i][time] = max(satisfaction[i]*time + count(satisfaction, i+1, n, time+1, dp), count(satisfaction, i+1, n, 1, dp));
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        
        int n = satisfaction.size();
        int maxi = *max_element(satisfaction.begin(), satisfaction.end());
        if(maxi <= 0) return 0;
        
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        
        return count(satisfaction, 0, n, 1, dp);
    }
};