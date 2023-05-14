class Solution {
public:
    int score(vector<int>& nums, int op, int n, vector<bool>& visited, unordered_map<vector<bool>, int>& dp) {
        
        if(op >= n) return 0;
        if(dp[visited]) return dp[visited];
        
        int ans = 0;
        
        for(int i=0 ; i<n ; i++) {
            if(visited[i]) continue;
            for(int j=i+1 ; j<n ; j++) {
                if(visited[j]) continue;
                
                visited[i] = true;
                visited[j] = true;
                
                int curr = op * gcd(nums[i], nums[j]);
                int next = score(nums, op+1, n, visited, dp);
                ans = max(ans, curr + next);
                
                visited[i] = false;
                visited[j] = false;
            }
        }
        
        return dp[visited] = ans;
    }
    
    int maxScore(vector<int>& nums) {
        
        int n = nums.size();
        vector<bool> visited(n);
        unordered_map<vector<bool>, int> dp;
        return score(nums, 1, n, visited, dp);
    }
};