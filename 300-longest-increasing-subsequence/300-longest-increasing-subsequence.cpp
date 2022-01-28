class Solution {
    int find(vector<int>& nums, int index, int n, int prev_index, vector<int>& dp) {
        
        if(index >= n) return 0;
        if(dp[prev_index+1] != -1) return dp[index];
        
        int taken = 0;
        int notTaken = find(nums, index+1, n, prev_index, dp);
        
        if(prev_index == -1 || nums[prev_index] < nums[index]) 
            taken = 1 + find(nums, index+1, n, index, dp);
        
        return dp[prev_index+1] = max(taken, notTaken);
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return 1;
        if(n == 2) {
            if(nums[0] < nums[1]) return 2;
            return 1;
        }
        
        vector<int> dp(n+1, -1);
        return find(nums, 0, n, -1, dp); // Recursive Memoization Approach
        
//         OR: Bottom Up Approach
//         for(int i=1 ; i<n ; i++) {
//             for(int j=0 ; j<i ; j++) {
//                 if(nums[i] > nums[j]) {
//                     dp[i] = max(dp[i], dp[j] + 1);
//                 }
//             }
//         }
        
//         return *max_element(dp.begin(), dp.end());
        
    }
};