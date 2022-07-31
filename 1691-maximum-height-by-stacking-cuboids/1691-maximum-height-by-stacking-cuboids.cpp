class Solution {
public:
    int height(vector<vector<int>>& cuboids, int i, int n, int prev, vector<vector<int>>& dp) {
        
        if(i >= n) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        
        int include = 0;
        
        if(prev == -1 || (cuboids[i][0] <= cuboids[prev][0] && cuboids[i][1] <= cuboids[prev][1] && cuboids[i][2] <= cuboids[prev][2])) 
            include = cuboids[i][2] + height(cuboids, i+1, n, i, dp);
        
        int exclude = 0 + height(cuboids, i+1, n, prev, dp);
        
        return dp[i][prev+1] = max(include, exclude);
    }
    
    int maxHeight(vector<vector<int>>& cuboids) {
        
        int n = cuboids.size();
        
        for(int i=0 ; i<n ; i++) {
            sort(cuboids[i].begin(), cuboids[i].end());
        }
        
        sort(cuboids.begin(), cuboids.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] == b[2] ? a[1] == b[1] ? a[0] > b[0] : a[1] > b[1] : a[2] > b[2];
        });
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return height(cuboids, 0, n, -1, dp);
    }
};