class Solution {
public:
    int money(vector<int>& cost, vector<int>& time, int i, int n, int wallRemaining, vector<vector<int>>& dp) {
        
        if(wallRemaining <= 0) return 0;
        if(i >= n) return 1e9;
        if(dp[i][wallRemaining] != -1) return dp[i][wallRemaining];
        
        int free = money(cost, time, i+1, n, wallRemaining, dp);
        
        // Here we reduce the wall count by the time[i] and additional -1 to reduced currently painted wall.
        int paid = cost[i] + money(cost, time, i+1, n, wallRemaining - time[i] - 1, dp);
        
        return dp[i][wallRemaining] = min(paid, free);
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        
        int n = cost.size();
        
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return money(cost, time, 0, n, n, dp);
    }
};