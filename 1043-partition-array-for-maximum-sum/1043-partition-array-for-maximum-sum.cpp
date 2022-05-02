class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        // dp[i] record the maximum sum we can get considering A[0] ~ A[i-1].
        // To get dp[i], we will try to change j last numbers separately to the maximum of them,
        // where j = 1 to j = K.
        
        int n = arr.size();
        if(k == 1) return accumulate(arr.begin(), arr.end(), 0);
        if(n == 1) return arr[0];
        if(n == 2) return max({ arr[0]*k, arr[1]*k, arr[0]+arr[1] });
        
        vector<int> dp(n+1, 0);
        
        for(int i=1 ; i<=n ; i++) {
            int x = 0;
            for(int j=1 ; j<=k && i-j>=0 ; j++) {
                x = max(x, arr[i-j]);
                dp[i] = max(dp[i], dp[i-j] + x*j);
            }
        }
        
        return dp[n];
    }
};