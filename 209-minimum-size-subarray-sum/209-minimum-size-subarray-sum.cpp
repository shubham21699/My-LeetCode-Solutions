class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) {
            if(nums[0] >= target) return 1;
            return 0;
        }
        
        int sum = 0;
        for(int i=0 ; i<n ; i++) sum += nums[i];
        
        if(sum < target) return 0;
        if(sum == target) return n;
        
        int maxLen = INT_MAX;
        int i = 0;
        int j = 0;
        sum = 0;
        
        while(j < n) {
            
            sum += nums[j];
            j++;
            
            while(sum >= target && i<j) {
                maxLen = min(maxLen, j-i);
                sum -= nums[i];
                i++;
            }
            
        }
        
        return maxLen;
        
//         // OR: O(n^2)
//         for(int i=0 ; i<n ; i++) {
//             sum = 0;
//             for(int j=i ; j<n ; j++) {
//                 sum += nums[j];
//                 if(sum >= target) {
//                     maxLen = min(maxLen, j-i+1);
//                     break;
//                 }
//             }
//         }
        
//         return maxLen;
    }
};