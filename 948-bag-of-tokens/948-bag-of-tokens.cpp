class Solution {
public:
    int maxScore(vector<int>& tokens, int i, int n, int power, int score, vector<vector<int>>& dp) {
        
        if(i >= n) return 0;
        if(dp[i][n] != -1) return dp[i][n];
        
        int ans = 0;
        if(power >= tokens[i]) ans = max(ans, 1 + maxScore(tokens, i+1, n, power-tokens[i], score+1, dp));
        if(score >= 1) ans = max(ans, -1 + maxScore(tokens, i, n-1, power+tokens[n-1], score-1, dp));
        
        return dp[i][n] = ans;
    }
    
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        int n = tokens.size();
        
        if(n == 1) {
            if(power >= tokens[0]) return 1;
            return 0;
        }
        
        sort(tokens.begin(), tokens.end());
        
        // 2 Pointer Approach:-
        int i = 0;
        int j = n-1;
        int score = 0;
        int result = 0;
        
        while(i <= j) {
            
            if(power >= tokens[i]) {
                power -= tokens[i];
                i++;
                score++;
                result = max(result, score);
            }
            else if(score >= 1) {
                power += tokens[j];
                j--;
                score--;
            }
            else break;
        }
        
        return result;
        
        
        // // OR: DP Approach - Will be accepted but slow
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return maxScore(tokens, 0, n, power, 0, dp);
    }
};