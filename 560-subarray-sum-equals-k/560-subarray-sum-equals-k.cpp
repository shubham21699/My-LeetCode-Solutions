class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(n == 1) {
            if(nums[0] == k) return 1;
            return 0;
        }
        
        unordered_map<int, int> prevSum;
        int current_sum = 0;
        int count = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            // Add current element to sum so far.
            current_sum += nums[i];
            
            // If current sum is equal to target sum, means subarray found and increase the count.
            if(current_sum == k) count++;
            
            // If current sum exceeds given sum by current_sum - target_sum.
            // Find number of subarrays having this sum and exclude those subarays 
            // from current sum by increasing count by same amount.
            if(prevSum.find(current_sum - k) != prevSum.end()) 
                count += prevSum[current_sum - k];
            
            // Add current sum value to count of different values of sum.
            prevSum[current_sum]++;
            
        }
        
        return count;
    }
};