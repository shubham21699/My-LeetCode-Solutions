class Solution {
public:
    int swaps(vector<int>& nums1, vector<int>& nums2, int i, int n, bool prevSwapped, vector<vector<int>>& dp) {
        
        if(i >= n) return 0;
        if(dp[i][prevSwapped] != -1) return dp[i][prevSwapped];
        
        int ways = INT_MAX;
        
        int prev1 = nums1[i-1];
        int prev2 = nums2[i-1];
        
        if(prevSwapped) swap(prev1, prev2);
        
        // No Swap
        if(nums1[i] > prev1 && nums2[i] > prev2) {
            ways = swaps(nums1, nums2, i+1, n, false, dp);
        }
        
        // If Swap to be performed
        if(nums1[i] > prev2 && nums2[i] > prev1) {
            ways = min(ways, 1 + swaps(nums1, nums2, i+1, n, true, dp));
        }
        
        return dp[i][prevSwapped] = ways;
    }
    
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        n++;
        bool prevSwapped = false;
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        return swaps(nums1, nums2, 1, n, prevSwapped, dp);
    }
};