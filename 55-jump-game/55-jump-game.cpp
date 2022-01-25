class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        if(n <= 1) return true;
        if(nums[0] == 0) return false;
        
        int distance = 0;
        for(int i=0 ; i<=distance ; i++) {
            distance = max(distance, i+nums[i]);
            if(distance >= n-1) return true;
        }
        
        return false;
    }
};