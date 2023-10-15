class Solution {
public:
    int mod = pow(10, 9) + 7;
    
    int ways(int position, int arrLen, int steps, vector<vector<int>>& dp) {
        
        if(position == 0 && steps == 0) return 1;
        if(position < 0 || position >= arrLen || steps < 0 || position > steps) return 0;
        if(dp[position][steps] != -1) return dp[position][steps];
        
        int count = (1LL*ways(position+1, arrLen, steps-1, dp)%mod + 
                     1LL*ways(position-1, arrLen, steps-1, dp)%mod + 
                     1LL*ways(position, arrLen, steps-1, dp)%mod) % mod;
        
        return dp[position][steps] = count;
    }
    
    int numWays(int steps, int arrLen) {
        
        vector<vector<int>> dp(steps/2+1, vector<int>(steps+1, -1));
        return ways(0, arrLen, steps, dp);
    }
};