class Solution {
    int points(vector<int>& nums, vector<int>& dp, int index, int n) {
        
        if(index >= n) return 0;
        if(dp[index] != 0) return dp[index];
        
        int current_ele = nums[index];
        int current_ind = index;
        int sum = 0;
        
        while(current_ind < n && nums[current_ind] == current_ele) {
            sum += current_ele;
            current_ind++;
        }
        
        while(current_ind < n && nums[current_ind] == (current_ele+1)) {
            current_ind++;
        }
        
        return dp[index] = max(sum + points(nums, dp, current_ind, n), points(nums, dp, index+1, n));
    }
    
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 0);
        return points(nums, dp, 0, n);
    }
};