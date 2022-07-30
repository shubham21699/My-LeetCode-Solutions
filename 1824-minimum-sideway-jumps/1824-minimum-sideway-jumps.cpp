class Solution {
public:
    int find(vector<int>& obstacles, int currLane, int currPos, vector<vector<int>>& dp) {
        
        int n = obstacles.size()-1;
        if(currPos == n) return 0;
        if(dp[currPos][currLane] != -1) return dp[currPos][currLane];
        
        if(obstacles[currPos+1] != currLane) {
            return find(obstacles, currLane, currPos+1, dp);
        }
        
        // Else
        int jumps = INT_MAX;
        
        for(int i=1 ; i<=3 ; i++) {
            
            if(currLane != i && obstacles[currPos] != i) {
                jumps = min(jumps, 1 + find(obstacles, i, currPos, dp));
            }
            
        }
        
        return dp[currPos][currLane] = jumps;
    }
    
    int minSideJumps(vector<int>& obstacles) {
        
        int n = obstacles.size();
        if(n == 1) return 0;
        if(n == 2) return 0;
        
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return find(obstacles, 2, 0, dp);
    }
};