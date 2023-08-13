class Solution {
public:
    bool partition(vector<int>& nums, int i, int n, vector<int>& dp) {
        
        if(i >= n) return true;
        if(dp[i] != -1) return dp[i];
        
        bool isGood = false;
        
        if(i < n-1 && nums[i] == nums[i+1]) {
            isGood |= partition(nums, i+2, n, dp);
        }
        if(i < n-2 && nums[i] == nums[i+1] && nums[i] == nums[i+2]) {
            isGood |= partition(nums, i+3, n, dp);
        }
        if(i < n-2 && nums[i+1]-nums[i] == 1 && nums[i+2]-nums[i+1] == 1) {
            isGood |= partition(nums, i+3, n, dp);
        }
        
        return dp[i] = isGood;
    }
    
    bool validPartition(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> dp(n, -1);
        return partition(nums, 0, n, dp);
    }
};