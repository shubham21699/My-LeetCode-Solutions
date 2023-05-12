class Solution {
public:
    long long collectPoints(vector<vector<int>>& questions, int i, int n, vector<long long>& dp) {
        
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        
        long long skip = collectPoints(questions, i+1, n, dp);
        long long done = questions[i][0] + collectPoints(questions, i+questions[i][1]+1, n, dp);
        return dp[i] = max(skip, done);
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        
        int n = questions.size();
        
        vector<long long> dp(n, -1);
        return collectPoints(questions, 0, n, dp);
    }
};