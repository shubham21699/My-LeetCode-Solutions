class Solution {
public:
    int LIS(vector<int>& nums, int i, int prev, int n, vector<vector<int>>& dp) {
        
        if(i >= n) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        
        int taken = 0, notTaken = 0;
        
        if(prev == -1 || nums[i] >= nums[prev]) taken = 1 + LIS(nums, i+1, i, n, dp);
        notTaken = LIS(nums, i+1, prev, n, dp);
        
        return dp[i][prev+1] = max(taken, notTaken);
    }
    
    int operations(vector<int>& nums, int i, int j, int n, vector<vector<int>>& dp) {
        
        if(j > n) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        int count = 0;
        
        for(int k=0 ; k<i ; k++) if(nums[k] != 1) count++;
        for(int k=i ; k<j ; k++) if(nums[k] != 2) count++;
        for(int k=j ; k<n ; k++) if(nums[k] != 3) count++;
        
        dp[i][j] = count;
        return min({ count, operations(nums, i, j+1, n, dp), operations(nums, i+1, j+1, n, dp)});
    }
    
    int minimumOperations(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return 0;
        if(n == 2) return nums[0] <= nums[1] ? 0 : 1;
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return n - LIS(nums, 0, -1, n, dp);
        
        // // OR:
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return operations(nums, 0, 0, n, dp);
    }
};