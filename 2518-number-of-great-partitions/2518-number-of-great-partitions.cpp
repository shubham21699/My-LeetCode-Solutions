class Solution {
public:
    int mod = pow(10, 9) + 7;
    
    int partition(vector<int>& nums, int index, int n, int k, int sum, vector<vector<int>>& dp) {
        
        if(sum > k) return 0;
        if(index >= n) return sum < k ? 1 : 0;
        if(dp[index][sum] != -1) return dp[index][sum];
        
        int taken = partition(nums, index+1, n, k, sum + nums[index], dp) % mod;
        int notTaken = partition(nums, index+1, n, k, sum, dp) % mod;
        
        return dp[index][sum] = (taken + notTaken) % mod;
    }
    
    int countPartitions(vector<int>& nums, int k) {
        
        int n = nums.size();
        long long totalSum = 0;
        for(int i=0 ; i<n ; i++) totalSum += nums[i];
        
        if(totalSum < 2*k) return 0;
        
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        
        int partitionsWithSumLessThanK = partition(nums, 0, n, k, 0, dp);
        
        int totalPossiblePartitions = 2; //pow(2, n) % mod;
        for(int i=1 ; i<n ; i++) totalPossiblePartitions = (totalPossiblePartitions * 2) % mod;
        
        return ((totalPossiblePartitions - (2 * partitionsWithSumLessThanK % mod)) + mod) % mod;
    }
};