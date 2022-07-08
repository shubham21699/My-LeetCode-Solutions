class Solution {
    long long solve(vector<int>& houses, int index, vector<vector<int>>& cost, int prev, int m, int n, int target, vector<vector<vector<int>>>& dp) {
        
        // If target is -ve means answer is not build as it has more neighbours.
        if(target < 0) return INT_MAX;
        
        // If we have visited all houses.
        if(index == m) {
            if(target == 0) return 0; // If neighbours are same as required.
            return INT_MAX; // If neighbours are not same as required.
        }
        
        if(dp[index][prev][target] != -1) return dp[index][prev][target];
        
        // If houses is already coloured.
        if(houses[index] != 0) {
            return dp[index][prev][target] = solve(houses, index+1, cost, houses[index], m, n, target - (prev != houses[index]), dp);
        }
        
        long long ans = INT_MAX; // If we are coloring a house, then find its min cost.
        
        for(int i=1 ; i<=n ; i++) {
            ans = min(ans, cost[index][i-1] + solve(houses, index+1, cost, i, m, n, target - (prev != i), dp));
        }
        
        return dp[index][prev][target] = ans;
    }
    
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+2, vector<int>(target+1, -1)));
        
        int ans = solve(houses, 0, cost, n+1, m, n, target, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};