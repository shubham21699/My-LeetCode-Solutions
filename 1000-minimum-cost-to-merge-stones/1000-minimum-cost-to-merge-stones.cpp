class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        
        int n = stones.size();
        if((n-1)%(k-1) != 0) return -1;
        
        if(k == 1 || n == k) {
            int sum = 0;
            for(int i=0 ; i<n ; i++) sum += stones[i];
            
            return sum;
        }
        
        vector<int> prefix_sum(n+1, 0);
        
        for(int i=0 ; i<n ; i++) {
            prefix_sum[i+1] = prefix_sum[i] + stones[i];
        }
        
        vector<vector<int> > dp(n, vector<int>(n, 0));
        
        // len is the current substring we are processing (sub-problem)
        for(int len=k ; len<=n ; len++) {
            // i and j are the span of the previous sub-problems, we are scanning over
            for(int i=0 ; i<=n-len ; i++) {
                
                int j = i+len-1;
                dp[i][j] = INT_MAX;
                
                // mid divides i-j into (1, rest), (K, rest), (2K-1, rest), etc....
                for(int mid=i ; mid<j ; mid+=k-1) {
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid+1][j]);
                }
                
                if((j-i) % (k-1) == 0) {
                    dp[i][j] += prefix_sum[j+1]-prefix_sum[i];
                }
                
            }
        }
        
        return dp[0][n-1];
    }
};