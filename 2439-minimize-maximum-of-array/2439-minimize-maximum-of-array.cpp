class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        
        int n = nums.size();
        long long minimizedValue = 0;
        long long sum = 0;
        
        // We calculate the prefix sum array and their average.
        // The average is the lower bound of the result, and it's reachable lower bound by the process in
        // intuition, so this average is the result.
        
        for(int i=0 ; i<n ; i++) {
            sum += nums[i];
            minimizedValue = max(minimizedValue, (sum + i) / (i + 1));
        }
        
        return minimizedValue;
    }
};