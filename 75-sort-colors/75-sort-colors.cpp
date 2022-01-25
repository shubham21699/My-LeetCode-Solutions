class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return;
        if(n == 2) {
            if(nums[0] > nums[1]) swap(nums[0], nums[1]);
            return;
        }
        
        int i = 0;
        int j = n-1;
        
        for(int k=0 ; k<=j ; k++) {
            
            while(nums[k] == 2 && k<j) {
                swap(nums[k], nums[j]);
                j--;
            }
            
            while(nums[k] == 0 && k>i) {
                swap(nums[k], nums[i]);
                i++;
            }
        }
        
    }
};