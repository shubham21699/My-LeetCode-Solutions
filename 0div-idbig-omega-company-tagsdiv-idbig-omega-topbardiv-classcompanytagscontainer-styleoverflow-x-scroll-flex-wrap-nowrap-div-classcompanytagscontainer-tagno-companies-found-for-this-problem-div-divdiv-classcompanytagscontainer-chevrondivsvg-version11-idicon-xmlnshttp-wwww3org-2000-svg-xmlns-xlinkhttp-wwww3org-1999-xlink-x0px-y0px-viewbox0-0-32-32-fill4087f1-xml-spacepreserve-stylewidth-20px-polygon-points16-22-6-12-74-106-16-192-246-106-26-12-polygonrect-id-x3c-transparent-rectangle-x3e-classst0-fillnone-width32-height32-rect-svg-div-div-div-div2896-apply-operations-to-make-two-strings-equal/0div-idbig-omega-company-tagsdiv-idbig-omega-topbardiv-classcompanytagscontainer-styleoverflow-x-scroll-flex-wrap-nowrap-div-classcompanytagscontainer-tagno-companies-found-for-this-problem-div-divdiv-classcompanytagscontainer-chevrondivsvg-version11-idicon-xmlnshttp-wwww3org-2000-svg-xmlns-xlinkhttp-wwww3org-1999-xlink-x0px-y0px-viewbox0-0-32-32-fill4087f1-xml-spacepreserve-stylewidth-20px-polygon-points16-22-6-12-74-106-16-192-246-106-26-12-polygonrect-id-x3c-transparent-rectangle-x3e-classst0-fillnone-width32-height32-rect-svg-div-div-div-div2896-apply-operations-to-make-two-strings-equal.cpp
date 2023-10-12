class Solution {
public:
    int operations(string s1, string s2, int x, vector<int>& indices, int i, int m, bool isOp1, vector<vector<int>>& dp) {
        
        if(i >= m) return 0;
        if(dp[i][isOp1] != -1) return dp[i][isOp1];
        
        int count = INT_MAX;
        
        if(i < m-1) {
            count = min(count, (indices[i+1]-indices[i]) + operations(s1, s2, x, indices, i+2, m, isOp1, dp));
        }
        
        count = min(count, x + operations(s1, s2, x, indices, i+1, m, true, dp));
        if(isOp1) count = min(count, operations(s1, s2, x, indices, i+1, m, false, dp));
        
        return dp[i][isOp1] = count;
    }
    
    int minOperations(string s1, string s2, int x) {
        
        int n = s1.length();
        if(s1 == s2) return 0;
        
        vector<int> indices;
        
        for(int i=0 ; i<n ; i++) {
            if(s1[i] != s2[i]) indices.push_back(i);
        }
        
        int m = indices.size();
        if(m % 2 != 0) return -1;
        
        vector<vector<int>> dp(m, vector<int>(2, -1));
        return operations(s1, s2, x, indices, 0, int(indices.size()), false, dp);
    }
};