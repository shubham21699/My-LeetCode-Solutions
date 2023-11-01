class Solution {
public:
    int LS(vector<int>& nums, int i, int n, int target, vector<vector<int>>& dp) {
        
        if(target == 0) return 0;
        if(target < 0 || i >= n) return -1001;
        if(dp[i][target] != -1) return dp[i][target];
        
        return dp[i][target] = max(1 + LS(nums, i+1, n, target-nums[i], dp), LS(nums, i+1, n, target, dp));
    }
    
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        int res = LS(nums, 0, n, target, dp);
        
        return res > 0 ? res : -1;
    }
};