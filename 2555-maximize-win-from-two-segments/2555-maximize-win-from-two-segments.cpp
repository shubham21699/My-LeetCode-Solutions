class Solution {
public:
    int win(vector<int>& prizePositions, int i, int n, int k, int segments, vector<vector<int>>& dp) {
        
        if(segments == 0 || i >= n) return 0;
        if(dp[i][segments] != -1) return dp[i][segments];
        
        int targetInd = lower_bound(prizePositions.begin(), prizePositions.end(), prizePositions[i]+k+1) - prizePositions.begin();
        
        return dp[i][segments] = max(targetInd - i + win(prizePositions, targetInd, n, k ,segments-1, dp), win(prizePositions, i+1, n, k, segments, dp));
    }
    
    int maximizeWin(vector<int>& prizePositions, int k) {
        
        int n = prizePositions.size();
        
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return win(prizePositions, 0, n, k, 2, dp);
    }
};