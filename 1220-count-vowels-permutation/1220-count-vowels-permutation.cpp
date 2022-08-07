class Solution {
public:
    int mod = pow(10, 9) + 7;
    unordered_map<char, int> mp = {
        { 'a', 1 },
        { 'e', 2 },
        { 'i', 3 },
        { 'o', 4 },
        { 'u', 5 }
    };
    
    long long count(char prev, int n, vector<vector<int>>& dp) {
        
        if(n == 0) return 1;
        if(dp[n][mp[prev]] != -1) return dp[n][mp[prev]];
        
        long long ans = 0;
        
        if(prev == 'a') ans = (ans + count('e', n-1, dp)) % mod;
        else if(prev == 'e') ans = (ans + count('a', n-1, dp) + count('i', n-1, dp)) % mod;
        else if(prev == 'i') ans = (ans + count('a', n-1, dp) + count('e', n-1, dp) + count('o', n-1, dp) + count('u', n-1, dp)) % mod;
        else if(prev == 'o') ans = (ans + count('i', n-1, dp) + count('u', n-1, dp)) % mod;
        else if(prev == 'u') ans = (ans + count('a', n-1, dp)) % mod;
        
        return dp[n][mp[prev]] = ans % mod;
    }
    
    int countVowelPermutation(int n) {
        
        if(n == 1) return 5;
        
        vector<vector<int>> dp(n+1, vector<int>(6, -1));
        
        return (long long) (count('a', n-1, dp) % mod + count('e', n-1, dp) % mod + count('i', n-1, dp) % mod + count('o', n-1, dp) % mod + count('u', n-1, dp) % mod) % mod;
    }
};