class Solution {
    int check(vector<int>& piles, vector<vector<int>>& dp, vector<int>& sum, int i, int M) {
        
        int n = piles.size();
        if(i == n) return 0; // We reach the end of the pile.
        
        // If 2*M is equal or more of the rest of the piles, then the player takes them all because
        // every player plays optimally.
        if(2*M >= n-i) return sum[i];
        
        // We might have been in this stage before with the same or the other player and so we already
        // know the optimal choice from this position.
        if(dp[i][M]) return dp[i][M];
        
        int mini = INT_MAX;
        
        // We calculate the more stones the next player will get for every choice of M, we will make
        // and we will choose the minimum of those.
        for(int j=1 ; j<=2*M ; j++) {
            mini = min(mini, check(piles, dp, sum, i+j, max(j, M)));
        }
        
        // The stones we will get are those in the sum array position, we stand minus the one the next
        // player will get.
        return dp[i][M] = sum[i]-mini;
    }
    
public:
    int stoneGameII(vector<int>& piles) {
        
        int n = piles.size();
        if(n == 1) return piles[0];
        if(n == 2) return piles[0]+piles[1];
        
        // vector<int> sum(piles.begin(), piles.end());
        vector<int> sum = piles;
        
        for(int i=n-2 ; i>=0 ; i--) {
            sum[i] += sum[i+1];
        }
        
        vector<vector<int>> dp(n, vector<int>(n+1, 0));
        check(piles, dp, sum, 0, 1);
        // Alice starts first and so she is at position 0 of piles and she begins with max 2*1 options.
        return dp[0][1];
    }
};