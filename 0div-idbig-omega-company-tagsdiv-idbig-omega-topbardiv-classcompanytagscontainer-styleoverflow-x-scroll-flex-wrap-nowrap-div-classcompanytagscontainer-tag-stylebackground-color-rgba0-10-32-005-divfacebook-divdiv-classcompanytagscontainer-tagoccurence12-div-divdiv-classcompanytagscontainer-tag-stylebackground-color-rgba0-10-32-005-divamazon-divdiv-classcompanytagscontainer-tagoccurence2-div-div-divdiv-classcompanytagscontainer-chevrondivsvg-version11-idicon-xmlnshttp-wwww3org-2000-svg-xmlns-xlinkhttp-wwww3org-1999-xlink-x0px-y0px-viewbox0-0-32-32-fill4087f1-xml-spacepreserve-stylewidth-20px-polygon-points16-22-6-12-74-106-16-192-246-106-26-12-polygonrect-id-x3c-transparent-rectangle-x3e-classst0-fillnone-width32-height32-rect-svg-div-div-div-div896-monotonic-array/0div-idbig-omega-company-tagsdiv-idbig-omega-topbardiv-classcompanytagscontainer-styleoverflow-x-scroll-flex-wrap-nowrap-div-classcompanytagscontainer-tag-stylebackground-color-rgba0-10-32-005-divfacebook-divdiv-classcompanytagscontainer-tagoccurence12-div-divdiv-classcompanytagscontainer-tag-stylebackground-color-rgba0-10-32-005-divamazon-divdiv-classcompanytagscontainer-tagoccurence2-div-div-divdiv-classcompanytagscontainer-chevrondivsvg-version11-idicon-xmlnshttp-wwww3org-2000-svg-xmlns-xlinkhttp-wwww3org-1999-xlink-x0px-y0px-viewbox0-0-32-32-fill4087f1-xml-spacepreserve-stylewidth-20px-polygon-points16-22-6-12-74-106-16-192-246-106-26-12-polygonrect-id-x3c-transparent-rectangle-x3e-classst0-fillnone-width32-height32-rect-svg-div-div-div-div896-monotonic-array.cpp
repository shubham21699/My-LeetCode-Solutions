class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return true;
        if(n == 2) return nums[0] <= nums[1] || nums[0] >= nums[1];
        
        bool inc = true, dec = true;
        
        for(int i=1 ; i<n ; i++) {
            inc &= (nums[i-1] <= nums[i]);
            dec &= (nums[i-1] >= nums[i]);
            
            if(!inc && !dec) return false;
        }
        
        return true;
    }
};