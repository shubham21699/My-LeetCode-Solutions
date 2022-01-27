class Solution {
    int find(vector<int>& nums, int index, int n, vector<int>& dp) {
        
        if(index >= n) return 0;
        if(dp[index] != -1) return dp[index];
        
        dp[index] = max(nums[index] + find(nums, index+2, n, dp), find(nums, index+1, n, dp));
        return dp[index];
    }
    
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        if(n == 3) return max(nums[0] + nums[2], nums[1]);
        
        vector<int> dp(n, -1);
        return find(nums, 0, n, dp);
    }
};