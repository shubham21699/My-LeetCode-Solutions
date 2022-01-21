class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return;
        
        int i = -1;
        
        for(int j=0 ; j<n ; j++) {
            if(nums[j] == 0) {
                i = j;
                break;
            }
        }
        
        if(i == -1) return;
        
        for(int j=0 ; j<n ; j++) {
            
            if(nums[j] != 0 && i<j) {
                swap(nums[i], nums[j]);
                i++;
            }

        }
        
    }
};