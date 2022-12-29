class Solution {
public:
    int mod = pow(10, 9) + 7;
    
    int NumberOfBeautifulPartitions(string& s, int i, int n, int k, int minLength, vector<vector<int>>& dp) {
        
        if(k == 0 && i >= n) return 1;
        if(k == 0 || i >= n) return 0;
        if(s[i] != '2' && s[i] != '3' && s[i] != '5' && s[i] != '7') return 0;
        if(dp[i][k] != -1) return dp[i][k];
        
        int count = 0;
        
        for(int j=i+minLength-1 ; j<n ; j++) {
            
            // Optimization to make is to break the loop when we can't form minLength*(k-1) partitions anymore.
            if(j + (minLength * (k - 1)) >= n) break;
            
            if(j-i+1 >= minLength && (s[i] == '2' || s[i] == '3' || s[i] == '5' || s[i] == '7') && (s[j] != '2' && s[j] != '3' && s[j] != '5' && s[j] != '7')) {
                count = (count + NumberOfBeautifulPartitions(s, j+1, n, k-1, minLength, dp)) % mod;
            }
        }
        
        return dp[i][k] = count;
    }
    
    int beautifulPartitions(string s, int k, int minLength) {
        
        int n = s.length();
        
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return NumberOfBeautifulPartitions(s, 0, n, k, minLength, dp);
    }
};