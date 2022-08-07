class Solution {
public:
    bool check(vector<int>& nums, int i, int j, int n, unordered_map<int, unordered_map<int, int>>& dp) {
        
        if(i >= n) return true;
        if(j >= n || j-i+1 >= 4) return false;
        if(dp.find(i) != dp.end() && dp[i].find(j) != dp[j].end()) return dp[i][j];
        
        bool ans = false;
        
        if(j-i+1 == 2) {
            if(nums[i] == nums[j]) ans |= check(nums, j+1, j+1, n, dp);
        }
        
        if(j-i+1 == 3) {
            if(nums[i] == nums[i+1] && nums[i] == nums[j]) ans |= check(nums, j+1, j+1, n, dp);
            if(nums[i+1]-nums[i] == 1 && nums[j]-nums[i+1] == 1) ans |= check(nums, j+1, j+1, n, dp);
        }
        
        ans |= check(nums, i, j+1, n, dp);
        return dp[i][j] = ans;
    }
    
    bool validPartition(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 2) return nums[0]==nums[1];
        
       unordered_map<int, unordered_map<int, int>> dp;
        return check(nums, 0, 0, n, dp);
    }
};