class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return 0;
        
        long long totalSum = 0;
        for(int i=0 ; i<n ; i++) totalSum += nums[i];

        int minDiff = INT_MAX;
        int minDiffIndex = 0;
        long long sum = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            sum += nums[i];
            totalSum -= nums[i];
            
            int diff = abs((sum / (i+1)) - (totalSum / max(1, n-i-1)));
            
            if(diff < minDiff) {
                minDiff = diff;
                minDiffIndex = i;
            }
        }
        
        return minDiffIndex;
    }
};