class Solution {
public:
    int maxSelectedChars(string& s, int i, int j, int n, unordered_set<string>& st, vector<vector<int>>& dp) {
        
        if(i > j || j >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int taken = 0, notTaken = 0;
        string x = s.substr(i, j-i+1);
        
        if(st.find(x) != st.end()) taken = (j-i+1) + maxSelectedChars(s, j+1, j+1, n, st, dp);
        notTaken = max(maxSelectedChars(s, i+1, j, n, st, dp), maxSelectedChars(s, i, j+1, n, st, dp));
        
        return dp[i][j] = max(taken, notTaken);
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        
        int n = s.length();
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return n - maxSelectedChars(s, 0, 0, n, st, dp);
    }
};