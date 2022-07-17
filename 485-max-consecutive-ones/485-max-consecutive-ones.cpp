class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0] == 1;
        
        int len = 0;
        int j = 0;
        int i = 0;
        
        while(i < n) {
            if(nums[i] == 0) {
                len = max(len, i-j);
                while(i<n && nums[i] == 0) i++;
                j = i;
            }
            else i++;
        }
        
        len = max(len, i-j);
        return len;
    }
};