class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        int n = nums.size();
        if(n == 1) {
            if(nums[0] == target) return 1;
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        vector<uint> dp(target+1, 0);
        dp[0] = 1;
        
        for(int i=1 ; i<=target ; i++) {
            for(auto& num : nums) {
                if(num > i) break;
                dp[i] += dp[i-num];
            }
        }
        
        return dp[target];
    }
};