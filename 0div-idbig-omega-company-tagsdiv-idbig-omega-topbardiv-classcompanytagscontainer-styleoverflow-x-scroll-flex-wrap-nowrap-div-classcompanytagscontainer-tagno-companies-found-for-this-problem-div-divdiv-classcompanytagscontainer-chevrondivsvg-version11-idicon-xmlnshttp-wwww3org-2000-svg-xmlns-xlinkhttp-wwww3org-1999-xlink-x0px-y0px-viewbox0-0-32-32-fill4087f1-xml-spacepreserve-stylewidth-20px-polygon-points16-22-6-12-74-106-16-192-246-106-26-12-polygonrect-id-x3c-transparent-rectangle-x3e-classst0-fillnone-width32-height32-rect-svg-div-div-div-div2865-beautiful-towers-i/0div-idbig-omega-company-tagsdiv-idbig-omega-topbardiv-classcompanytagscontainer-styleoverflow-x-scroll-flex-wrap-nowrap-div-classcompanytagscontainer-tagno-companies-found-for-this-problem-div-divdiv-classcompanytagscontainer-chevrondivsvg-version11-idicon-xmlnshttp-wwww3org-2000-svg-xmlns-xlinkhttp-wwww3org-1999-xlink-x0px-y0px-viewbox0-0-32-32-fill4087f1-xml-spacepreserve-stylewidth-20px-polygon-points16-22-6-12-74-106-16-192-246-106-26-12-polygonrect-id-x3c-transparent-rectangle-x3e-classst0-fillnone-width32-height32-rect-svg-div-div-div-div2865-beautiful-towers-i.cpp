class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        
        int n = maxHeights.size();
        if(n == 1) return maxHeights[0];
        if(n == 2) return (long long) (maxHeights[0] + maxHeights[1]);
        
        long long result = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            vector<int> heights = maxHeights;
            long long sum = heights[i];
            
            for(int j=i-1 ; j>=0 ; j--) {
                heights[j] = min(heights[j], heights[j+1]);
                sum += heights[j];
            }
            
            for(int k=i+1 ; k<n ; k++) {
                heights[k] = min(heights[k], heights[k-1]);
                sum += heights[k];
            }
            
            result = max(result, sum);
        }
        
        return result;
    }
};