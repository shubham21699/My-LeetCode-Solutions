class Solution {
public:
    int cost(vector<int>& nums, int i, int n, int k, vector<vector<int>>& trimmed, vector<int>& dp) {
        
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        
        int ans = INT_MAX;
        
        for(int j=i ; j<n ; j++) {
            ans = min(ans, k + trimmed[i][j] + cost(nums, j+1, n, k, trimmed, dp));
        }
        
        return dp[i] = ans;
    }
    
    int minCost(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(n == 1) return k;
        
        vector<vector<int>> trimmed(n, vector<int>(n));
        
        for(int i=0 ; i<n ; i++) {
            
            unordered_map<int, int> freq;
            int count = 0;
            
            for(int j=i ; j<n ; j++) {
                if(freq.find(nums[j]) != freq.end()) {
                    if(freq[nums[j]] == 1) count += 2;
                    else count++;
                }
                
                freq[nums[j]]++;
                trimmed[i][j] = count;
            }
            
        }
        
        vector<int> dp(n, -1);
        return cost(nums, 0, n, k, trimmed, dp);
    }
};