class Solution {
    int find(vector<int>& nums, int sum, int target, int index, int n, vector<unordered_map<int, int> >& dp) {

        if(sum == target && index >= n) return 1;
        if(index >= n) return 0;
        
        if(dp[index].find(sum) != dp[index].end()) return dp[index][sum];
        
        dp[index][sum] = find(nums, sum-nums[index], target, index+1, n, dp) + find(nums, sum+nums[index], target, index+1, n, dp);
        
        return dp[index][sum];
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        if(n == 1) {
            if(abs(nums[0]) == abs(target)) return 1;
            return 0;
        }
        
        vector<unordered_map<int, int > > dp(n+1);
        return find(nums, 0, target, 0, n, dp);
    }
};