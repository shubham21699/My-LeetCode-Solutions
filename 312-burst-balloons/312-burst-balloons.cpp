class Solution {
public:
    int burst(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
        
        int n = nums.size();
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int coins = 0;
        
        for(int k=i ; k<=j ; k++) {
            int left = i == 0 ? 1 : nums[i-1];
            int right = j == n-1 ? 1 : nums[j+1];
            int mid = nums[k];
            
            coins = max(coins, left*mid*right + burst(nums, i, k-1, dp) + burst(nums, k+1, j, dp));
        }
        
        return dp[i][j] = coins;
    }
    
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return burst(nums, 0, n-1, dp);
    }
};