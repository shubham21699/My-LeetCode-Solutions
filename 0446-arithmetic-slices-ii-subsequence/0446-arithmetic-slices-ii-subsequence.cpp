class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size();

        // dp[i] = Hash table of <diff, seq length ending at ith element>  
        vector<unordered_map<long long, long long>> dp(n);
        long long slices = 0;
        
        for(int i=0 ; i<n ; i++) {
            // For the current element, find all the longest arithmetic sequences 
            // that can end here for a given difference
            
            for(int j=0 ; j<i ; j++) {
                
                // Current diff with a number in [0:i) 
                long long diff = (long long) nums[i] - nums[j];
                
                // The current number can be appended at the end of all the 
                // sequences which were found till jth index for the given diff
                // Also the ith and jth number can also form a seq of length 2, hence the + 1
                long long count = dp[j].count(diff) ? dp[j][diff] + 1 : 1;
                
                dp[i][diff] += count;
                
                // Since (nums[i], nums[j]) have size of 2, so we remove it, hence -1
                slices += count-1;
            }
        }
        
        
        return slices;
    }
};