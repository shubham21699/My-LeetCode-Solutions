class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        int n = nums.size();
        int minInd = -1, maxInd = -1;
        int indexOfLastSubarrayEnd = -1;
        bool minKFound = false, maxKFound = false;
        long long count = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            if(nums[i] < minK || nums[i] > maxK) {
                indexOfLastSubarrayEnd = i;
                minKFound = false;
                maxKFound = false;
            }
            if(nums[i] == minK) {
                minInd = i;
                minKFound = true;
            }
            if(nums[i] == maxK) {
                maxInd = i;
                maxKFound = true;
            }
            
            // There can be (min(minInd, maxInd) - indexOfLastSubarrayEnd) choices
            if(minKFound && maxKFound) {
                count += min(minInd, maxInd) - indexOfLastSubarrayEnd;
            }
        }

        return count;
    }
};