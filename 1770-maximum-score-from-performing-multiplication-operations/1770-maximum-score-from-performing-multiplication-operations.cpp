class Solution {
public:
    int score(vector<int>& nums, vector<int>& multipliers, int i, int j, int k, int m, vector<vector<int>>& dp) {
        
        if(k >= m) return 0;
        if(dp[i][k] != INT_MIN) return dp[i][k];
        
        return dp[i][k] = max(multipliers[k]*nums[i] + score(nums, multipliers, i+1, j, k+1, m, dp), multipliers[k]*nums[j] + score(nums, multipliers, i, j-1, k+1, m, dp));
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        int n = nums.size();
        int m = multipliers.size();

        vector<vector<int>> dp(m, vector<int>(m, INT_MIN));
        return score(nums, multipliers, 0, n-1, 0, m, dp);
    }
};