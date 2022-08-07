class Solution {
public:
    long long merge(vector<int>& stones, int l, int r, int k, vector<vector<int>>& dp) {
        
        if(l == r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        
        long long ans = INT_MAX;
        
        for(int i=l ; i<r ; i+=k-1) {
            ans = min(ans, merge(stones, l, i, k, dp) + merge(stones, i+1, r, k, dp));
        }
        
        if((r-l) % (k-1) == 0) {
            for(int i=l ; i<=r ; i++) ans += stones[i];
        }
        
        return dp[l][r] = ans;
    }
    
    
    int mergeStones(vector<int>& stones, int k) {
        
        int n = stones.size();
        if(n == 1) return 0;
        if(n == 2) return k==2 ? stones[0] + stones[1] : -1;
        if(n == k) return accumulate(stones.begin(), stones.end(), 0);
        if((n-1) % (k-1) != 0) return -1;
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return merge(stones, 0, n-1, k, dp);
        
//         // OR:
//         int n = stones.size();
//         if((n-1)%(k-1) != 0) return -1;
        
//         if(k == 1 || n == k) {
//             int sum = 0;
//             for(int i=0 ; i<n ; i++) sum += stones[i];
            
//             return sum;
//         }
        
//         vector<int> prefix_sum(n+1, 0);
        
//         for(int i=0 ; i<n ; i++) {
//             prefix_sum[i+1] = prefix_sum[i] + stones[i];
//         }
        
//         vector<vector<int> > dp(n, vector<int>(n, 0));
        
//         // len is the current substring we are processing (sub-problem)
//         for(int len=k ; len<=n ; len++) {
//             // i and j are the span of the previous sub-problems, we are scanning over
//             for(int i=0 ; i<=n-len ; i++) {
                
//                 int j = i+len-1;
//                 dp[i][j] = INT_MAX;
                
//                 // mid divides i-j into (1, rest), (K, rest), (2K-1, rest), etc....
//                 for(int mid=i ; mid<j ; mid+=k-1) {
//                     dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid+1][j]);
//                 }
                
//                 if((j-i) % (k-1) == 0) {
//                     dp[i][j] += prefix_sum[j+1]-prefix_sum[i];
//                 }
                
//             }
//         }
        
//         return dp[0][n-1];
    }
};