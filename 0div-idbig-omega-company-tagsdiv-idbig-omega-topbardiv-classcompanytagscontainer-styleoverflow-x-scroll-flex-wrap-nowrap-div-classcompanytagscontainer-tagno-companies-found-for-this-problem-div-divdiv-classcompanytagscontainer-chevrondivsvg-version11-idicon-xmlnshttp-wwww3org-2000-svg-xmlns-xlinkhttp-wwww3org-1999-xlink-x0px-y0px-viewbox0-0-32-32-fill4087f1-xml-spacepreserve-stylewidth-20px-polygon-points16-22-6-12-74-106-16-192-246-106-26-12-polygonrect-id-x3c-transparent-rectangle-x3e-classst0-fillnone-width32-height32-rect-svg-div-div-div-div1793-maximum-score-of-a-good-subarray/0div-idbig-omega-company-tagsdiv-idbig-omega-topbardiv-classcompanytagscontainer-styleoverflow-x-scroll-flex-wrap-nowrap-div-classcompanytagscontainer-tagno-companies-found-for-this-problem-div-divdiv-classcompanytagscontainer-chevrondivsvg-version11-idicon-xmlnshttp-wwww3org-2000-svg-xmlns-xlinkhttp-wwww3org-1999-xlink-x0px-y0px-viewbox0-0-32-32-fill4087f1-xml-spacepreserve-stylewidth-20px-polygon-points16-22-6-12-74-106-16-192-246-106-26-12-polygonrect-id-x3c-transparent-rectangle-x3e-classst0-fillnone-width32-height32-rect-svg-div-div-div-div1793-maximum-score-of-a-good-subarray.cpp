class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        
        int n = nums.size();
        int i = k, j = k;
        int result = nums[k];
        int mini = nums[k];
        
        while(i > 0 || j < n-1) {
            if((j+1 < n ? nums[j+1] : 0) > (i-1 >= 0 ? nums[i-1] : 0)) mini = min(mini, nums[++j]);
            else mini = min(mini, nums[--i]);
            
            result = max(result, mini * (j-i+1));
        }
        
        return result;
    }
};