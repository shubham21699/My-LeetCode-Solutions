class Solution {
    int amount(vector<int>& nums, int index, int n) {
        
        int maxAmount = 0;
        int prevAmount = 0;
        
        for(int i=index ; i<n ; i++) {
            int temp = max(nums[i] + prevAmount, maxAmount);
            prevAmount = maxAmount;
            maxAmount = temp;
        }
        
        return maxAmount;
    }
    
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        if(n == 3) return max({ nums[0], nums[1], nums[2] });
        
        return max(amount(nums, 0, n-1), amount(nums, 1, n));
    }
};