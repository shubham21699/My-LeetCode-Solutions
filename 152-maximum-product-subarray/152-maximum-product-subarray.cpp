class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        
        int mini = 1;
        int maxi = 1;
        int result = INT_MIN;
        
        for(int i=0 ; i<n ; i++) {
            
            if(nums[i] < 0) swap(mini, maxi);
            
            mini = min(nums[i], mini*nums[i]);
            maxi = max(nums[i], maxi*nums[i]);
            
            result = max(result, maxi);
            
        }
        
        return result;
    }
};