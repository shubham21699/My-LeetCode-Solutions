class Solution {
public:
    int solve(vector<int>& values, int i, int j, vector<vector<int>>& dp) {
        
        if(j-i < 2) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        
        for(int k=i+1 ; k<j ; k++) {
            ans = min(ans, values[i]*values[k]*values[j] + solve(values, i, k, dp) + solve(values, k, j, dp));
        }
        
        return dp[i][j] = ans;
    }
    
    int minScoreTriangulation(vector<int>& values) {
        
        int n = values.size();
        if(n == 3) return values[0] * values[1] * values[2];
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(values, 0, n-1, dp);
    }
};