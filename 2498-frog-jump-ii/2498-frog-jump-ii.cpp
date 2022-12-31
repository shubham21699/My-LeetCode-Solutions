class Solution {
public:
    int maxJump(vector<int>& stones) {
        
        int n = stones.size();
        if(n <= 3) return stones[n-1] - stones[0];
        
        // Skipping just one stone in every forward jump and jumping to those skipped stones 
        // in backward jump can minimize the maximum jump.
        
        int cost = 0;
        
        // Travel forward to last stone:
        for(int i=0 ; i<n-2 ; i+=2) {
            cost = max(cost, stones[i+2] - stones[i]);
        }
        
        if(n%2 != 0) cost = max(cost, stones[n-1] - stones[n-2]);
        
        
        // Travel back to first stone:
        int i = n-1;
        if(n%2 != 0) {
            cost = max(cost, stones[i] - stones[i-1]);
            i--;
        }
        
        for(; i>1 ; i-=2) {
            cost = max(cost, stones[i] - stones[i-2]);
        }
        
        return cost;
    }
};