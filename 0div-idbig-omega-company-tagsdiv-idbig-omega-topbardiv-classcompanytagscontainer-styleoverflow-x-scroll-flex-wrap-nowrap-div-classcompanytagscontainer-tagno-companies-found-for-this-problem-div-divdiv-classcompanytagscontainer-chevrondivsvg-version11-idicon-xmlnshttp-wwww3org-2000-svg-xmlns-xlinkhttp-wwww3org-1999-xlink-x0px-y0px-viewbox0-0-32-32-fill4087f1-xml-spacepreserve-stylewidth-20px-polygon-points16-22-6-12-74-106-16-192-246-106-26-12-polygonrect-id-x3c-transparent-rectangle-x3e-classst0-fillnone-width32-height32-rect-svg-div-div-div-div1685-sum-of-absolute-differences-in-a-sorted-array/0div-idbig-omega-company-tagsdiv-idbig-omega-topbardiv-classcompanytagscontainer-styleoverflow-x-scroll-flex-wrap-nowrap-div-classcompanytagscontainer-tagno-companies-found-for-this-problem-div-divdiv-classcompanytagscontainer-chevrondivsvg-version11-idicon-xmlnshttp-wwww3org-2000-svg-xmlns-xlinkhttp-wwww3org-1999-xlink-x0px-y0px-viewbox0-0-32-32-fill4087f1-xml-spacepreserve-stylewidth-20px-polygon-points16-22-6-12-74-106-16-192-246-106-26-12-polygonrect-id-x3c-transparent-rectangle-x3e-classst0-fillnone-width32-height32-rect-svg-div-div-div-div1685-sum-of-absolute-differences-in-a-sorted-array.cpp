class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> prefixSum = nums;
        
        for(int i=1 ; i<n ; i++) prefixSum[i] += prefixSum[i-1];
        
        vector<int> result(n);
        
        for(int i=0 ; i<n ; i++) {
            
            int leftSum = prefixSum[i] - nums[i];
            int rightSum = prefixSum[n-1] - prefixSum[i];
            
            int leftCount = i;
            int rightCount = n-1-i;
            
            result[i] = ((leftCount * nums[i]) - leftSum) + (rightSum - (rightCount * nums[i]));
        }
        
        return result;
    }
};