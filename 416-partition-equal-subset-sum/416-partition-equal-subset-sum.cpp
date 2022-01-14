class Solution {
    bool find(vector<int>& nums, int sum, int req_sum, int index, int n, vector<vector<int> >& dp) {
        
        if(sum == req_sum) return true;
        if(index >= n || sum > req_sum) return false;
        if(dp[index][sum] != -1) return dp[index][sum];
        
        dp[index][sum] = find(nums, sum+nums[index], req_sum, index+1, n, dp) || find(nums, sum, req_sum, index+1, n, dp);
        
        return dp[index][sum];
        
    }
    
public:
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int sum = 0;
        
        for(int i=0 ; i<n ; i++) sum += nums[i];
        
        if(sum % 2 != 0) return false;
    
        int req_sum = sum/2;
        
        vector<vector<int> > dp(n+1, vector<int>(sum + 1, -1));
        sum = 0;
        
        return find(nums, sum, req_sum, 0, n, dp);
        
    }
};