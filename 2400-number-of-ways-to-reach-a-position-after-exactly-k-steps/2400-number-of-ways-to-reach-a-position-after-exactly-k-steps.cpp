class Solution {
public:
    int mod = pow(10, 9) + 7;
    
    int ways(int currPos, int endPos, int k, int steps, unordered_map<int, unordered_map<int, int>>& dp) {
        
        if(currPos == endPos && steps == k) return 1;
        if(abs(endPos - currPos)+steps == k) return 1;
        if(steps >= k || abs(endPos - currPos)+steps > k) return 0;
        if(dp[currPos][steps]) return dp[currPos][steps];
        
        return dp[currPos][steps] = (ways(currPos+1, endPos, k, steps+1, dp) + ways(currPos-1, endPos, k, steps+1, dp)) % mod;
    }
    
    int numberOfWays(int startPos, int endPos, int k) {
        
        if((abs(endPos - startPos) + k) % 2 != 0) return 0;
        
        unordered_map<int, unordered_map<int, int>> dp;
        return ways(startPos, endPos, k, 0, dp);
    }
};