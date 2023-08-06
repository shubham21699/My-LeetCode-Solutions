class Solution {
public:
    int mod = pow(10, 9) + 7;
    
    long long playlists(int n, int goal, int k, vector<vector<int>>& dp) {
        
        if(n == 0 && goal == 0) return 1;
        if(n == 0 || goal == 0) return 0;
        if(dp[n][goal] != -1) return dp[n][goal];
        
        // pick: We choose a song for the current position in the playlist. There are n choices for the first
        // position, n - 1 for the second, and so on. So, we multiply solve(n - 1, goal - 1, k, dp) by n to
        // count all valid playlists when we pick a song for the current position.
        // notPick: We do not choose a song for the current position. In this case, we can select any song from
        // the remaining max(n - k, 0) songs (to ensure there are at least k songs between repeated songs). 
        // So, we multiply solve(n, goal - 1, k, dp) by max(n - k, 0)
        
        long long pick = playlists(n-1, goal-1, k, dp) * n;
        long long notPick = playlists(n, goal-1, k, dp) * max(0, n-k);
        
        return dp[n][goal] = (pick + notPick) % mod;
    }
    
    int numMusicPlaylists(int n, int goal, int k) {
        
        vector<vector<int>> dp(n+1, vector<int>(goal+1, -1));
        return playlists(n, goal, k, dp);
    }
};