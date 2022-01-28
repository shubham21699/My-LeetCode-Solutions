class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size()-1;
        
        for(int i=0 ; i<=n ; i++) {
            int index = abs(nums[i]);
            nums[index] = -1 * nums[index];
            
            // After multiplying with -1, a duplicate number gets to its original +ve value 
            // after its 2nd appearance and when that appears return absolute of that duplicate value.
            if(nums[index] > 0) return abs(nums[i]);
        }
        
        return -1;
    }
};