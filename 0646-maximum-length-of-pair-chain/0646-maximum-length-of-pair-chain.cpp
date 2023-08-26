class Solution {
public:
    int chain(vector<vector<int>>& pairs, int i, int j, int n, vector<vector<int>>& dp) {
        
        if(i >= n) return 0;
        if(dp[i][j+1] != -1) return dp[i][j+1];
        int taken = 0, notTaken = 0;
        
        if(j == -1 || pairs[i][0] > pairs[j][1]) taken = 1 + chain(pairs, i+1, i, n, dp);
        notTaken = chain(pairs, i+1, j, n, dp);
        
        return dp[i][j+1] = max(taken, notTaken);
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b){
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return chain(pairs, 0, -1, n, dp);
    }
};