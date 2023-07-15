class Solution {
public:
    int attend(vector<vector<int>>& events, int i, int n, int k, int prevEndTime, vector<vector<int>>& dp) {
        
        if(k == 0 || i >= n) return 0;
        if(prevEndTime >= events[i][0]) return attend(events, i+1, n, k, prevEndTime, dp);
        if(dp[i][k] != -1) return dp[i][k];
        
        int taken = events[i][2] + attend(events, i+1, n, k-1, events[i][1], dp);
        int notTaken = attend(events, i+1, n, k, prevEndTime, dp);
        
        return dp[i][k] = max(taken, notTaken);
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        
        int n = events.size();
        sort(events.begin(), events.end());
        
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return attend(events, 0, n, k, 0, dp);
    }
};