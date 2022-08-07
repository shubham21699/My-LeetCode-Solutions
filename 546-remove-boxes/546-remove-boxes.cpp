class Solution {
public:
    int remove(vector<int>& boxes, int l, int r, int k, vector<vector<vector<int>>>& dp) {
        
        if(l > r) return 0;
        if(dp[l][r][k] != -1) return dp[l][r][k];
        
        int orgK = k;
        int orgL = l;
        
        // Increase both 'l' and 'k' if they have consecutive colors with 'boxes[l]'
        while(l < r && boxes[l] == boxes[l+1]) {
            k++;
            l++;
        }
        
        // Remove all boxes which has the same with 'boxes[l]'
        int ans = (k+1)*(k+1) + remove(boxes, l+1, r, 0, dp);
        
        for(int i=l+1 ; i<=r ; i++) { // Try to merge non-contiguous boxes of the same color together
            if(boxes[i] == boxes[l])
                ans = max(ans, remove(boxes, l+1, i-1, 0, dp) + remove(boxes, i, r, k+1, dp));
        }
        
        return dp[orgL][r][orgK] = ans;
    }
    
    int removeBoxes(vector<int>& boxes) {
        
        int n = boxes.size();
        if(n == 1) return 1;
        if(n == 2) return boxes[0]==boxes[1] ? 4 : 2;
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return remove(boxes, 0, n-1, 0, dp);
    }
};