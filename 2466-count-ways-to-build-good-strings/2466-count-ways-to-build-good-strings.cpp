class Solution {
public:
    int mod = pow(10, 9) + 7;
    
    int count(int strLen, int zero, int one, int low, int high, vector<int>& dp) {
        
        if(strLen > high) return 0;
        if(dp[strLen] != -1) return dp[strLen];
        
        int val = 0;
        if(strLen >= low && strLen <= high) val++;
        
        int countStr0 = count(strLen + zero, zero, one, low, high, dp);
        int countStr1 = count(strLen + one, zero, one, low, high, dp);
        
        return dp[strLen] = (val + countStr0 + countStr1) % mod;
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        
        vector<int> dp(high+1, -1);
        return count(0, zero, one, low, high, dp);
    }
};