class Solution {
    int maxLength(vector<int>& nums1, vector<int>& nums2, int i, int j, int& ans, int n, int m, vector<vector<int>>& dp) {
        
        if(i >= n || j >= m) return 0;
        if(dp[i][j] != 0) return dp[i][j];
        
        int count = 0;
        if(nums1[i] == nums2[j]) count = 1 + maxLength(nums1, nums2, i+1, j+1, ans, n, m, dp);
        
        maxLength(nums1, nums2, i+1, j, ans, n, m, dp);
        maxLength(nums1, nums2, i, j+1, ans, n, m, dp);
        
        ans = max(ans, count);
        return dp[i][j] = count;
    }
    
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        if(n == 1 && m == 1) return nums1[0] == nums2[0];
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        int ans = 0;
        
        for(int i=1 ; i<=n ; i++) {
            for(int j=1 ; j<=m ; j++) {
                if(nums1[i-1] == nums2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = 0;
                
                ans = max(ans, dp[i][j]);
             }
        }
        
        return ans;
        
        // // OR: 
        // maxLength(nums1, nums2, 0, 0, ans, n, m, dp);
        // return ans;
    }
};