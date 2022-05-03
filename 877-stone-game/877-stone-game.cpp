class Solution {
    vector<vector<int>> dp;
    
    bool game(vector<int>& piles, int alice, int bob, int i, int j) {
        
        if(i >= j) {
            return alice > bob;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = game(piles, alice+piles[i], bob+piles[i+1], i+2, j) || game(piles, alice+piles[i], bob+piles[j], i+1, j-1) || game(piles, alice+piles[j], bob+piles[j-1], i, j-2) || game(piles, alice+piles[j], bob+piles[i], i+1, j-1);
        
    }
    
public:
    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size();
        int alice = 0;
        int bob = 0;
        dp.clear();
        dp.resize(n, vector<int>(n, -1));
        
        return game(piles, alice, bob, 0, n-1);
    }
};