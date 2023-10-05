class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        int count = 1;
        int bit = INT_MAX;
        
        for(int i=0 ; i<n ; i++) {
            
            bit &= nums[i];
            
            if(bit == 0) {
                count++;
                bit = INT_MAX;
            }
            
        }
        
        if(bit > 0) count--;
        return max(1, count);
    }
};