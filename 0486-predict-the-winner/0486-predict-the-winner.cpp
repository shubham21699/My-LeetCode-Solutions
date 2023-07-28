class Solution {
public:
    int winner(vector<int>& nums, int i, int j, int turn, vector<vector<int>>& dp) {
        
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        
        if(turn == 1) {
            int first = nums[i] + winner(nums, i+1, j, 2, dp);
            int last = nums[j] + winner(nums, i, j-1, 2, dp);
            ans = max(first, last);
        }
        if(turn == 2) {
            int first = -nums[i] + winner(nums, i+1, j, 1, dp);
            int last = -nums[j] + winner(nums, i, j-1, 1, dp);
            ans = min(first, last);
        }
        
        return dp[i][j] = ans;
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return winner(nums, 0, n-1, 1, dp) >= 0;
    }
};