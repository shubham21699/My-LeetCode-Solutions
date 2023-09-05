class Solution {
public:
    int operations(string& num, int i, int special, int n, vector<vector<int>>& dp) {
        
        if(i >= n) {
            if(special % 25 == 0) return 0;
            return n+1;
        }
        if(dp[i][special] != -1) return dp[i][special];
        
        int notDelete = operations(num, i+1, (special*10 + (num[i]-'0')) % 25, n, dp);
        int deleteCurr = 1 + operations(num, i+1, special, n, dp); 
        
        return dp[i][special] = min(deleteCurr, notDelete);
    }
    
    int minimumOperations(string num) {
        
        int n = num.length();
        if(n == 1) return num == "0" ? 0 : 1;
        
        vector<vector<int>> dp(n+1, vector<int>(25, -1));
        return operations(num, 0, 0, n, dp);
    }
};