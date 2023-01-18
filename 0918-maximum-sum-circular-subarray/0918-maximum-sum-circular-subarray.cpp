class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int n = nums.size();
        int maxSum = nums[0];
        int minSum = nums[0];
        int currMax = 0;
        int currMin = 0;
        int totalSum = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            currMax += nums[i];
            maxSum = max(maxSum, currMax);
            if(currMax < 0) currMax = 0;
            
            currMin += nums[i];
            minSum = min(minSum, currMin);
            if(currMin > 0) currMin = 0;
            
            totalSum += nums[i];
        }
        
        return maxSum > 0 ? max(maxSum, totalSum - minSum) : maxSum;
        
//         // OR:
//         int maxSum = INT_MIN;
        
//         for(int i=0 ; i<n ; i++) {
            
//             maxSum = max(maxSum, nums[i]);
//             int sumLeft = nums[i];
//             int sumRight = nums[i];
//             int j = (i-1+n) % n;
//             int k = (i+1) % n;
            
//             while(j != i) {
//                 sumLeft += nums[j];
//                 maxSum = max(maxSum, sumLeft);
//                 j = (j-1+n) % n;
//             }
            
//             while(k != i) {
//                 sumRight += nums[k];
//                 maxSum = max(maxSum, sumRight);
//                 k = (k+1) % n;
//             }
            
//         }
        
//         return maxSum;
    }
};