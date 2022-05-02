class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums;
        if(n == 2) {
            if(nums[0]%2 == 0) return nums;
            if(nums[1]%2 == 0) {
                swap(nums[0], nums[1]);
                return nums;
            }
        }
        
        int i = 0;
        
        while(i < n && nums[i]%2 == 0) i++;
        
        int j = i;
        
        while(i < n) {
            if(nums[i] % 2 == 0) {
                swap(nums[i], nums[j]);
                j++;
            }
            
            i++;
        }
        
        return nums;
    }
};