class Solution {
public:
    int dotProduct(vector<int>& nums1, vector<int>& nums2, int i, int j, int n, int m, vector<vector<int>>& dp) {
        
        if(i >= n || j >= m) return INT_MIN;
        if(dp[i][j] != INT_MIN) return dp[i][j];
        
        int prod = nums1[i] * nums2[j];
        
        return dp[i][j] = max({ prod + max(dotProduct(nums1, nums2, i+1, j+1, n, m, dp), 0), 
                               dotProduct(nums1, nums2, i+1, j, n, m, dp), 
                               dotProduct(nums1, nums2, i, j+1, n, m, dp)});
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        
        vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
        return dotProduct(nums1, nums2, 0, 0, n, m, dp);
    }
};