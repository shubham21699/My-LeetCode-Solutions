class Solution {
    int diff(vector<int>& stones, int i, int j, int sum, vector<vector<int>>& dp) {
        
        if(sum <= 0) return 0;
        if(i == j) return 0;
        if(dp[i][j]) return dp[i][j];
        
        return dp[i][j] = max(sum - stones[i] - diff(stones, i+1, j, sum-stones[i], dp), sum - stones[j] - diff(stones, i, j-1, sum-stones[j], dp));
    }
    
public:
    int stoneGameVII(vector<int>& stones) {
        
        int n = stones.size();
        if(n == 2) return max(stones[0], stones[1]);
        
        int sum = accumulate(stones.begin(), stones.end(), 0);
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        return diff(stones, 0, n-1, sum, dp);
    }
};