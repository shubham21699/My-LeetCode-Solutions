class Solution {
public:
    int maxCanEat(vector<int>& slices, int i, int n, int count, vector<vector<int>>& dp) {
        
        if(count == 0 || i >= n) return 0;
        if(dp[i][count] != -1) return dp[i][count];
        
        return dp[i][count] = max(slices[i] + maxCanEat(slices, i+2, n, count-1, dp), maxCanEat(slices, i+1, n, count, dp));
    }
    
    int maxSizeSlices(vector<int>& slices) {
        
        int n = slices.size();
        if(n == 3) return max({ slices[0], slices[1], slices[2] });
        
        vector<vector<int>> dp(n, vector<int>(n/3+1, -1));
        int case1 = maxCanEat(slices, 0, n-1, n/3, dp);
        
        dp = vector<vector<int>>(n, vector<int>(n/3+1, -1));
        int case2 = maxCanEat(slices, 1, n, n/3, dp);
        
        return max(case1, case2);
    }
};