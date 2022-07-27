class Solution {
public:
    int find(vector<int>& cuts, int n, int i, int j, vector<vector<int>>& dp) {
        
        if(j-i <= 1) return 0;
        if(dp[i][j] != 0) return dp[i][j];
        
        int cost = INT_MAX;
        
        for(int k=i+1 ; k<j ; k++) {
            cost = min(cost, cuts[j] - cuts[i] + find(cuts, n, i, k, dp) + find(cuts, n, k, j, dp));
        }
        
        return dp[i][j] = cost;
    }
    
    int minCost(int n, vector<int>& cuts) {
        
        int m = cuts.size();
        if(n == m) return n;
        
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        m += 2;
        
        vector<vector<int>> dp(m+1, vector<int>(m+1, 0));
        return find(cuts, n, 0, m-1, dp);
    }
};