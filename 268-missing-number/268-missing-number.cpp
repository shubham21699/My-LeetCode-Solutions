class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        int bit = 0;
        
        for(int i=0 ; i<n ; i++) {
            bit ^= nums[i];
            bit ^= i;
        }
        
        bit ^= n;
        return bit;
    }
};