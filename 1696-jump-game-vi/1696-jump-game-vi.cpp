class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        if(k == 1) return accumulate(nums.begin(), nums.end(), 0);
        
        vector<int> dp(n, 0);
        priority_queue<pair<int, int>> pq;
        
        for(int i = n-1 ; i >= 0 ; i--) {
            
            while(pq.size() && pq.top().second > i+k) {
                pq.pop();
            }
            
            dp[i] = nums[i] + (pq.size() ? pq.top().first : 0);
            pq.push({ dp[i], i });
        }
        
        return dp[0];
    }
};