class Solution {
public:
    int mod = pow(10, 9) + 7;
    
    int ways(string& s, int i, int n, int k, vector<int>& dp) {
        
        if(i >= n) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        
        int count = 0;
        long long num = 0;
        
        for(int j=i ; j<n ; j++) {
            
            num = num*10 + (s[j]-'0');
            if(num > k) break;
            
            count = (count + ways(s, j+1, n, k, dp)) % mod;
        }
        
        return dp[i] = count;
    }
    
    int numberOfArrays(string s, int k) {
        
        int n = s.length();
        
        vector<int> dp(n, -1);
        return ways(s, 0, n, k, dp);
    }
};