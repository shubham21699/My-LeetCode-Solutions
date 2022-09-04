class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int maxLen = 1;
        long long val = 0;
        int i = 0;
        
        for(int j=0 ; j<n ; j++) {
            
            while((val & nums[j]) != 0 && i<=j) {
                val ^= nums[i];
                i++;
            }
            
            val ^= nums[j];
            maxLen = max(maxLen, j-i+1);
        }

        return maxLen;
    }
};