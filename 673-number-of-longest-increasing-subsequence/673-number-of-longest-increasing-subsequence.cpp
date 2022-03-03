class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return 1;
        
        vector<int> lis(n, 1); // Stores length of longest sequence till i-th position.
        vector<int> count(n, 1); // Stores count of longest sequence of length lis[i].
        int maxLen = 1; // Maximum length of LIS.
        
        for(int i=1 ; i<n ; i++) {
            for(int j=0 ; j<i ; j++) {
                if(nums[i] > nums[j]) {
                    // Means Strictly Increasing.
                    if(lis[j] + 1 > lis[i]) { 
                        lis[i] = lis[j] + 1;
                        count[i] = count[j];
                    }
                    // Means there are more subsequences of same length ending at length lis[i].
                    else if(lis[j] + 1 == lis[i]) {
                        count[i] += count[j];
                    }
                }
            }
            
            maxLen = max(maxLen, lis[i]);
        }
        
        int noOfLIS = 0;
        
        // Count all the subsequences of length maxLen
        for(int i=0 ; i<n ; i++) {
            if(lis[i] == maxLen) {
                noOfLIS += count[i];
            }
        }
        
        return noOfLIS;
    }
};