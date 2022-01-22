class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return;
        if(n == 2) {
            swap(nums[0], nums[1]);
            return;
        }
        
        int i = n-2;
        
        for(i=n-2 ; i>=0 ; i--) {
            if(nums[i] < nums[i+1]) {
                break;
            }
        }
        
        reverse(nums.begin()+i+1, nums.end());
        if(i == -1) return;
        
        for(int j=i+1 ; j<n ; j++) {
            if(nums[i] < nums[j]) {
                swap(nums[i], nums[j]);
                break;
            }
        }
        
    }
};