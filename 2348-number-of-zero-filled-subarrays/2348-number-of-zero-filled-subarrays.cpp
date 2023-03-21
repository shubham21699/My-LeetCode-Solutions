class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        int n = nums.size();
        long long result = 0;
        
        for(int i=0 ; i<n ; i++) {
            if(nums[i] == 0) {
                int subArrLen = 0;
                
                while(i < n && nums[i] == 0) {
                    subArrLen++;
                    i++;
                }
                
                result += ((long long) ((long long)subArrLen * (long long)(subArrLen+1)))/2;
            }
        }
        
        return result;
    }
};