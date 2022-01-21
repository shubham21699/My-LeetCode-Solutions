class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return;
        
        int i = -1;
        
        // Store the index of 1st occurrence of 0 in array
        for(int j=0 ; j<n ; j++) {
            if(nums[j] == 0) {
                i = j;
                break;
            }
        }
        
        // If 0 doesn't exist, then just return
        if(i == -1) return;
        
        // Else make changes
        for(int j=0 ; j<n ; j++) {
            
            if(nums[j] != 0 && i<j) {
                swap(nums[i], nums[j]);
                i++;
            }

        }
        
    }
};