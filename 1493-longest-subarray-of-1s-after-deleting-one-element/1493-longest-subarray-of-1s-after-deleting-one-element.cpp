class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return 0;
        if(n == 2) {
            if(nums[0] xor nums[1] == 1) return 1;
            return 0;
        }
        
        int i = 0;
        int maxLen = 0;
        int count0 = 0;
        int zeroInd = -1;
        int j = i;
        
        while(i < n && j < n) {
            
            if(nums[j] == 0) count0++;
            if(j < n && count0 <= 1) j++;
            else {
                maxLen = max(maxLen, j-i-1);
                i = zeroInd+1;
                count0 = 0;
            }
            
            if(nums[j-1] == 0) zeroInd = j-1;
            
        }
        
        maxLen = max(maxLen, j-i-1);
        return maxLen;
    }
};