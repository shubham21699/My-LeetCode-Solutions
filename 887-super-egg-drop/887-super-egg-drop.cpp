class Solution {
public:
    int solve(int eggs, int floors, vector<vector<int>>& dp) {
        
        if(floors == 0 || floors == 1) return floors;
        if(eggs == 1) return floors;
        if(dp[eggs][floors] != -1) return dp[eggs][floors];
        
        int ans = INT_MAX;
        
        // Binary Search Approach -
        int start = 1;
        int end = floors;
        
        while(start <= end) {
            
            int midFloor = start + (end - start)/2;
            
            int left = solve(eggs - 1, midFloor - 1, dp);
            int right = solve(eggs, floors - midFloor, dp);
            
            int ansForCurrFloor = 1 + max(left, right);
            
            if(left < right) start = midFloor + 1;
            else end = midFloor - 1;
            
            ans = min(ans, ansForCurrFloor);
        }
        
        
//         // Now for every possible floor we check the moves required
//         for(int i=1 ; i<=floors ; i++) {
            
//             // Every floor we visit will contribute 1 to our answer
//             // The maximum condition is for the 2 cases discussed for each floor:
//             // Case 1: If the egg breaks then decrease the egg count and move to below floor
//             // Case 2: If it doesn't breaks then egg count remains same and move floors upward.
            
//             // Will give TLE -
//             int ansForCurrFloor = 1 + max(solve(eggs - 1, i - 1, dp), solve(eggs, floors - i, dp));
            
//             // Choose the minimum from each floor calculated.
//             ans = min(ans, ansForCurrFloor);
//         }
        
        return dp[eggs][floors] = ans;
    }
    
    int superEggDrop(int eggs, int floors) {
        
        if(floors <= 1) return floors;
        if(eggs == 1) return floors;
        
        vector<vector<int>> dp(eggs+1, vector<int>(floors+1, -1));
        
        return solve(eggs, floors, dp);
    }
};