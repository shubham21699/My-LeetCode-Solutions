class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return true;
        
        for(int i=1 ; i<n ; i++) {
            if(nums[i] < nums[i-1]) {
                if(i-2 < 0 || nums[i-2] <= nums[i]) nums[i-1] = nums[i];
                else nums[i] = nums[i-1];
                break;
            }
        }
        
        for(int i=0 ; i<n-1 ; i++) {
            if(nums[i] > nums[i+1]) return false;
        }
        
        return true;
    }
};