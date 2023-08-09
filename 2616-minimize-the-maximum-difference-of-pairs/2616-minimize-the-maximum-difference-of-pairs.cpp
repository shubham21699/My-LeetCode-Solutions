class Solution {
public:
    int minmax(vector<int>& nums, int i, int n, int p, vector<vector<int>>& dp) {
        
        if(p == 0) return 0;
        if(i >= n-1) return INT_MAX;
        if(dp[i][p] != -1) return dp[i][p];
        
        int notTake = minmax(nums, i+1, n, p, dp);
        int take = max((nums[i+1] - nums[i]), minmax(nums, i+2, n, p-1, dp));
        
        return dp[i][p] = min(take, notTake);
    }
    
    bool check(vector<int>& nums, int n, int p, int x) {
        
        int i = 0;
        
        while(i < n-1) {
            
            if(nums[i+1] - nums[i] <= x) {
                p--;
                i += 2;
            }
            else i++;
            
        }
        
        return p <= 0;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int left = 0;
        int right = nums[n-1] - nums[0];
        int ans = -1;
        
        while(left <= right) {
            
            int mid = left + (right - left) / 2;
            
            if(check(nums, n, p, mid)) {
                ans = mid;
                right = mid-1;
            }
            else left = mid+1;
            
        }
        
        return ans;
        
        
        // OR: Will give Memory Limit Exceeded
        // vector<vector<int>> dp(n, vector<int>(p+1, -1));
        // return minmax(nums, 0, n, p, dp);
    }
};