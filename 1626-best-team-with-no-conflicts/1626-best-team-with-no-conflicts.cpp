class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
        int n = scores.size();
        vector<vector<int>> v;
        
        for(int i=0 ; i<n ; i++) v.push_back({ ages[i], scores[i] });
        
        sort(v.begin(), v.end());
        int score = 0;
        vector<int> dp(n);
        
        for(int i=0 ; i<n ; i++) {
            dp[i] = v[i][1];
            
            for(int j=0 ; j<i ; j++) {
                if(v[j][1] <= v[i][1]) dp[i] = max(dp[i], dp[j] + v[i][1]);
            }
            
            score = max(score, dp[i]);
        }
        
        return score;
    }
};