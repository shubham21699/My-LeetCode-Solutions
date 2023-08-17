class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        
        // If n == 1, done.
        // If n == 2, split once, done.
        // Otherwise we must have a middle status, that one array has length 2 and nums[i] + nums[i+1] >= m.
        
        int n = nums.size();
        if(n == 1 || n == 2) return true;
        
        for(int i=0 ; i<n-1 ; i++) {
            if(nums[i] + nums[i+1] >= m) return true;
        }
        
        return false;
    }
};