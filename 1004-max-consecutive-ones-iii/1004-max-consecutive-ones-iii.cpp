class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n = nums.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        int countZero = 0;
        
        while(j < n) {
            
            if(nums[j] == 0) countZero++;
            while(countZero > k) {
                if(nums[i] == 0) countZero--;
                i++;
            }
            
            ans = max(ans, j-i+1);
            j++;
        }
        
        return ans;
    }
};