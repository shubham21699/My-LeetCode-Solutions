class Solution {
public:
    bool cross(vector<int>& stones, int i, int n, int lastJump, unordered_map<int, unordered_map<int, int>>& dp) {
        
        if(i == n-1) return true;
        if(dp[i].find(lastJump) != dp[i].end()) return dp[i][lastJump];
        bool ans = false;
        
        for(int j=i+1 ; j<n ; j++) {
            if(stones[j]-stones[i] > lastJump+1) break;
            if(stones[j]-stones[i] == lastJump-1 || stones[j]-stones[i] == lastJump || stones[j]-stones[i] == lastJump+1) {
                ans |= cross(stones, j, n, stones[j]-stones[i], dp);
            }
        }
        
        return dp[i][lastJump] = ans;
    }
    
    bool canCross(vector<int>& stones) {
        
        int n = stones.size();
        if(stones[1] - stones[0] > 1) return false;
        if(n == 2) return stones[1] - stones[0] == 1;
        
        unordered_map<int, unordered_map<int, int>> dp;
        return cross(stones, 1, n, 1,  dp);
    }
};