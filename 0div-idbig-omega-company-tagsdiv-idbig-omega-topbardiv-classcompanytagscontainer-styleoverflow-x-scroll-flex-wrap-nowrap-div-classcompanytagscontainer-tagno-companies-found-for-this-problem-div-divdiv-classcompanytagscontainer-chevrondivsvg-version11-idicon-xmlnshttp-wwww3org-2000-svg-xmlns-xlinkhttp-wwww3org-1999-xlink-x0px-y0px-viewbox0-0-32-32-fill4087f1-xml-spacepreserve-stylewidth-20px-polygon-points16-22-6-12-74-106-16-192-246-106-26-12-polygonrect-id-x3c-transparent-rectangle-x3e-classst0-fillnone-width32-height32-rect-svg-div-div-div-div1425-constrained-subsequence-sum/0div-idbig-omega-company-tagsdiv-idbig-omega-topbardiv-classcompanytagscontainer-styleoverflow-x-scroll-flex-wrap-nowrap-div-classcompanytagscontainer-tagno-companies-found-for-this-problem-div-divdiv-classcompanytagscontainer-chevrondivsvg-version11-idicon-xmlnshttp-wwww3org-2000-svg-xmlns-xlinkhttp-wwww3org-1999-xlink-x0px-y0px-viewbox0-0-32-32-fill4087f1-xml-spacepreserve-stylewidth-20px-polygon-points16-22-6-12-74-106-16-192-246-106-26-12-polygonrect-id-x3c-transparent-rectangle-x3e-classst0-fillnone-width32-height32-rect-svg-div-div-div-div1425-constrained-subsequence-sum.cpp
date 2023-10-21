class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> dp = nums;
        int maxSum = dp[0];
        priority_queue<pair<int, int>> pq;
        pq.push({ dp[0], 0 });
        
        for(int i=1 ; i<n ; i++) {
            while(!pq.empty() && pq.top().second < i-k) pq.pop();
            
            dp[i] = max(dp[i], nums[i] + pq.top().first);
            pq.push({ dp[i], i });
            maxSum = max(maxSum, dp[i]);
        }
        
        return maxSum;
        
//         // OR: Will give TLE
//         for(int i=1 ; i<n ; i++) {
//             for(int j=i-1 ; i-j<=k && j>=0 ; j--) {
//                 dp[i] = max(dp[i], nums[i] + dp[j]);
//             }
            
//             maxSum = max(maxSum, dp[i]);
//         }
        
//         return maxSum;
    }
};