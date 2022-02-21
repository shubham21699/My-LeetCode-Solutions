class Solution {
    int minCost(vector<int>& cost, vector<int>& dp, int index, int n) {
        
        if(index >= n) return 0;
        if(dp[index] != 0) return dp[index];
        
        return dp[index] = min(cost[index] + minCost(cost, dp, index+1, n), cost[index] + minCost(cost, dp, index+2, n));
        
    }
    
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        if(n == 1) return cost[0];
        if(n == 2) return min(cost[0], cost[1]);
        
        vector<int> dp(n, 0);
        return min(minCost(cost, dp, 0, n), minCost(cost, dp, 1, n));
    }
};